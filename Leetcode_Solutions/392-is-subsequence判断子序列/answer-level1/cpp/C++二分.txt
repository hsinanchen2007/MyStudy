
```cpp
    bool isSubsequence(string s, string t) {
        vector<int> mp[26];
        for(int i = 0; i < t.size(); i++) mp[t[i]-'a'].push_back(i);
        for(int i = 0, j = 0; i < s.size(); i++){
            vector<int> &vec = mp[s[i]-'a'];//将要查找的序列
            int l = 0, r = vec.size()-1, target = j;//在vec里找第一个>=target的数
            while(l < r){
                int mid = l + r >> 1;
                if(vec[mid] >= target) r = mid;
                else l = mid + 1;
            }
            if(r<0||vec[l] < target) return false;//失败
            else j = vec[l]+1;
        }
        return true;
    }
```