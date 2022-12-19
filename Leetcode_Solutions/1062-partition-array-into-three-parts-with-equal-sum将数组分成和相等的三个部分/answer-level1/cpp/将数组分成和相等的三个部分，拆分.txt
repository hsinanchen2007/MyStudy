划分成三个相同的部分，首先可以求出数组和s，进行一个判断。
之后寻找数组是否存在三块，每一块的和都为s/3;

```cpp
class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int s = accumulate(A.begin(),A.end(),0);
        int len = A.size();
        if(len<3 || s%3!=0){
            return false;
        }
        int tar = s/3;
        int i=0;
        vector<bool> res(3,false);
        for(int j=0;j<3;j++){
            int tmp=0;
            for(;i<len;i++){
                tmp += A[i];
                if(tmp == tar){
                    i++;
                    res[j] = true;
                    break;
                }
            }
        }
        return res[0] && res[1] && res[2];
    }
};
```

![image.png](https://pic.leetcode-cn.com/3b3107bb892729f5eb49fa159ba4c7e36bc177006e70e005d68b9eae8038c647-image.png)

可以小改一下
```cpp
class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int s = accumulate(A.begin(),A.end(),0);
        int len = A.size();
        if(len<3||s%3!=0){
            return false;
        }
        int tar = s/3;
        int i=0;
        int count = 0;
        for(int j=0;j<3;j++){
            int tmp=0;
            for(;i<len;i++){
                tmp += A[i];
                if(tmp==tar){
                    i++;
                    count++;
                    break;
                }
            }
        }
        return count==3;
    }
};
```