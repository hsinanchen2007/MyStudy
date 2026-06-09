效率还可以：
![微信图片_20200331095647.png](https://pic.leetcode-cn.com/2a05207a401347fa7072e331750df14fccbe2bf15c9fe375df2632b76c95f243-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20200331095647.png)


```
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int k=27;
        if(target<letters[0]||target>=letters[letters.size()-1]){
            return letters[0];
        }
        for(int i=0;i<letters.size();i++){
            if(letters[i]-target>0){
                k=min(k,letters[i]-target);
            }
        }
        return k+target;
    }
};
```

