```
class Solution {
    public int numWays(int n) {
        if(n == 0) return 1;
        if(n == 1) return 1;
        if(n == 2) return 2;
        int i[] = new int[n];//先定义一个足够的数组
        i[0] = 1;
        i[1] = 2;
        for(int j =2; j < n; j++){
            i[j] = (i[j-1]+i[j-2])%1000000007;
        }
        return i[n-1];
    }
}
```
![image.png](https://pic.leetcode-cn.com/c5cb6d9cd7412f02bb9f0539ed98123073fccadc09aa3ef7baae6072e9883f73-image.png)

```
class Solution {
    public int numWays(int n) {
        if(n == 0) return 1;
        if(n == 1) return 1;
        if(n == 2) return 2;
        int i[] = {1,2,0};//长度为3的数组   
        i[0] = 1;
        i[1] = 2;
        //每次循环用数组第0为位装n-2对应的值 第一位装n-1对应的值 第二位装n对应的值 节省空间
        for(int j =2; j < n; j++){
            i[2] = (i[1]+i[0])%1000000007;
            i[0] = i[1];
            i[1] = i[2];
        }
        return i[n-1];
    }
}
```
![image.png](https://pic.leetcode-cn.com/ff1c3d05c7dcbc7ac35becb4f730059e5eea9c476c39fa196877efd286de24c5-image.png)


