### 解题思路
![image.png](https://pic.leetcode-cn.com/b336c20a0ea2c5cc72db64fddb018a0e6d2fd4ee17a93319cfd7c0190e37fdd9-image.png)
![image.png](https://pic.leetcode-cn.com/03711073ba062067f6ee89b16fffb3af34f9a6f8e0d7e516db31b0a12c17c184-image.png)



### 代码

```cpp
class Solution {
public:
    int game(vector<int>& guess, vector<int>& answer) {
        int j=0;
        for(int i=0;i<3;i++){
            if (guess[i]==answer[i]){
                j++;
            }
        }
        return j;
    }
};
```