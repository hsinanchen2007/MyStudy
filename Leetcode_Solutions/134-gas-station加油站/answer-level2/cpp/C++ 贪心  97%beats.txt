### 解题思想
1. 首先，如果想要跑完一圈，那么汽油的添加量一定大于消耗量，这是基础，返回值用三目运算符实现
2. 其次，从0开始遍历，如果累加的gas_now第一次小于0时，说明前面的经过的结点都不能作为开始点，start=i+1，即开始点偏移到当前指针i的下一个位置
3. 如果汽油的添加量一定大于消耗量，则开始点一定存在，不用担心偏移下一个位置带来的越界问题

### 代码
```
int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int gas_now=0,start=0,total=0;
        for(int i=0;i<gas.size();++i)//寻找出发点
        {
            total+=gas[i]-cost[i];
            gas_now+=gas[i]-cost[i];
            if(gas_now<0) {
                start=i+1;
                gas_now=0;
            }    
        }
        return total>=0?start:-1;
    }
```


### 运行结果
![image.png](https://pic.leetcode-cn.com/ea301a73782d4807905ffeb477df7500f01af95af8a854469cda7f5facb465e5-image.png)
