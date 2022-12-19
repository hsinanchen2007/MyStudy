
### 方法一：数学方法
![39264c1a8ddf023c70cba1bc437c1c0c0af1729305919b5f6d4c18254db07168-图片.png](https://pic.leetcode-cn.com/63b5ab58408d2644d2bf85a04046dd496394cc85e7afe8f17e9debd8d82af7d2-39264c1a8ddf023c70cba1bc437c1c0c0af1729305919b5f6d4c18254db07168-%E5%9B%BE%E7%89%87.png)

```cpp
class Solution {
public:
    vector<int> grayCode(int n) {
        int total=pow(2,n);
        vector<int> res(total,0);
        for(int i=0;i<total;i++){
            res[i]=(i>>1)^i;
        }
        return res;
    }
};


### 方法二：

[镜像反射法，图解](https://leetcode-cn.com/problems/gray-code/solution/gray-code-jing-xiang-fan-she-fa-by-jyd/)

```cpp
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        res.push_back(0);
        if(n==0) return res;
        int head = 1;
        for (int i = 0; i < n; i++) {
            for (int j = res.size() - 1; j >= 0; j--){
                res.push_back(head + res[j]);
            }
            head <<= 1;
        }
        return res;
    }
};