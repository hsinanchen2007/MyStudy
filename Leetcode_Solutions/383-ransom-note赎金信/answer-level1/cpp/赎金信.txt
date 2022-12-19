**用两个map分别保存两个字符串中的每个字符及其出现次数，然后比较即可。**
```cpp
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char, int> m1, m2;
        int i, j, l1 = ransomNote.size(), l2 = magazine.size();
        for(i = 0; i < l1; i++){
            if(m1.find(ransomNote[i]) == m1.end())
                m1[ransomNote[i]] = 1;
            else
                m1[ransomNote[i]]++;
        }
        for(i = 0; i < l2; i++){
            if(m2.find(magazine[i]) == m2.end())
                m2[magazine[i]] = 1;
            else
                m2[magazine[i]]++;
        }
        if(m1.size() > m2.size())
            return false;
        map<char, int>::iterator it;
        for(it = m1.begin(); it != m1.end(); it++){
            if(m2.find(it->first) == m2.end() || m2[it->first] < it->second)
                return false;
        }
        return true;
    }
};
```