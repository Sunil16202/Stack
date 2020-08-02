#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// design the class:

#include<bits/stdc++.h>
unordered_map<int, int> mp;
list<int> dq;
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
        if(mp.find(key)==mp.end())
            return -1;
        dq.remove(key);
        dq.push_front(key);
        return mp[key];
        
        
    }
    
    static void set(int key, int value){
        
      if(mp.find(key)==mp.end())
    {
        if(dq.size()==sz)
        {
            mp.erase(dq.back());
            dq.pop_back();
        }
    }else
        dq.remove(key);
    mp[key] = value;
    dq.push_front(key);
        

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