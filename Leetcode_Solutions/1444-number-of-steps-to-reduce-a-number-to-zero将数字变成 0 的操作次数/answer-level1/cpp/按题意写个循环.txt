class Solution {
public:
    int numberOfSteps (int num) {
        int count=0;
        for(;num!=0;)
        {
            if(num%2==0)
              num=num/2;
            else
              num=num-1;
            count++;
        }
        return count;
    }
};

![QQ图片20200209130100.png](https://pic.leetcode-cn.com/bf56b0c93ac1216d00a813946ddcf4d55a19e8309a7e79a3fff9b57b31a6ffdc-QQ%E5%9B%BE%E7%89%8720200209130100.png)
