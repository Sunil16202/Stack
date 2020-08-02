#include <bits/stdc++.h>
using namespace std;


unordered_map<int, int> mp;
deque<int> dq;
int sz;

class LRUCache
{
private:

public:
    LRUCache(int capacity)
    {
        // constructor for cache
        sz = capacity;
        mp.clear();
        dq.clear();
    }
    
    static int get(int key)
    {
        // this function should return value corresponding to key
        if(mp.find(key)==mp.end()){
            return -1;
        }
        
        auto it = dq.begin();
        while(*it!=key){
            it++;
        }
        dq.erase(it);
        dq.push_back(key);
        return mp[key];
        
        
    }
    
    static void set(int key, int value){
        
        //not found in the hashmap
        if(mp.find(key)==mp.end()){
            if(dq.size() == sz){
                mp.erase(dq.front());
                dq.pop_front();
            }
        }
        //element found in the hashmap
        else{
            //remove the current element from the deque
            auto it = dq.begin();
            while(*it!=key){
                it++;
            }
            dq.erase(it);
        }
        mp[key] = value;
        dq.push_back(key);
        

    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);
        
        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->set(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends