```
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";   //向量长度为空，返回“”
        string res=strs[0];     //以第一个为标准
        int vecSize=strs.size();
        for(int i=1;i<vecSize;i++){    //与向量的元素逐个比较
            int length=res.length();
            for(int j=0;j<length;j++){
                if(res[j]==strs[i][j]){
                    continue;   
                }
                else{
                    res.erase(j);
                    break;
                }
            }
        }
        return res;
    }
};
```
![image.png](https://pic.leetcode-cn.com/74773421b26f6b1f879f9648bff4e29abed354f74ca321e11e29a5e3b54b0249-image.png)

