```
struct HashData
{
    int key;
    int value;
};
class MyHashMap {
public:
    /** Initialize your data structure here. */
    vector<vector<HashData>> data;
    int hash_len = 1024;
    MyHashMap() {
        vector<HashData> d;
        for(int i=0; i<1024; i++)
        {
            data.push_back(d);
        }
    }
    
    int hashFunc(int n)
    {
        return (n & 0x3f) ^ (n >> 10);
    }

    /** value will always be non-negative. */
    void put(int key, int value) {
        int i = hashFunc(key);
        HashData n;
        vector<HashData>& d = data[i];
        for(int j=0; j<d.size(); j++)
        {
            if(d[j].key == key)
            {
                d[j].value = value;
                return;
            }
        }
        n.key = key;
        n.value = value;
        d.push_back(n);
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int i = hashFunc(key);
        vector<HashData>& d = data[i];
        for(int j=0; j<d.size(); j++)
        {
            if(d[j].key == key)
            {
                return d[j].value;
            }
        }
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int i = hashFunc(key);
        vector<HashData>& d = data[i];
        for(int j=0; j<d.size(); j++)
        {
            if(d[j].key == key)
            {
                d.erase(d.begin()+j);
                break;
            }
        }
    }
};
```
