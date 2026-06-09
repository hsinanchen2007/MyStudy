### 解题思路
根据题意，第一步统计出相同数字的张数，第二步判断是否可以配对，以下提供两种方法：

## 法一：采用gcd方法

主要是求多个数的最大公约数：由gcd(a,b,c) = gcd( gcd(a,b) , c) ，可知，通过遍历张数数组，迭代计算出与上一次的最大公约数 的 最大公约数，当为1时，不必继续计算，因为由公式可知往后计算的结果也是1，所以直接return false。
如果完整遍历，则在结束时判断x是否大于2即可。

详见以下代码：

### 代码

```cpp
class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        int num[10000]={0};
        for(int i=0;i<deck.size();i++) //统计每个数出现的次数（张数数组）
        {
            num[deck[i]]++;
        }
        int x = 0;
        for(int j=0;j<10000;j++)
        {
            if(num[j]>0)
            {
                x = gcd(x,num[j]);      //由 gcd(a,b,c) = gcd( gcd(a,b) , c)
                if(x==1)            //如果提前等于11，说明往后计算最大公约数只能为1，直接false
                return false;
            }
        }
        return x>=2?true:false;     //最大公约数起码得>=2，才说明可以配对
    }
    int gcd(int a, int b)
    {
        return b ==0?a:gcd(b,a%b);
    }
};
```


## 法二：不用gcd的暴力枚举法

统计完出来之后，找到张数数组的最小值，然后从2到最小值，分别去 除 张数数组的每一个数值 ，当有一个数可以整除所有张数时，即可返回true。
这里做了一个优化，**比如当2不能整除9时，那么2的倍数（2,4,6,8）均不可以整除9**，所以类似素数筛的原理把其倍数全部筛掉，用一个bool数组来记录是否被筛即可。

详见以下代码：

### 代码

```cpp
class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        int num[10000]={0};
        for(int i=0;i<deck.size();i++) //统计每个数出现的次数（张数数组）
        {
            num[deck[i]]++;
        }
        int min = INT_MAX;
        vector<int> s;
        for(int j=0;j<10000;j++) 
        {
            if(num[j]>0){
            s.push_back(num[j]);     //把张数数组的 值 放在s数组
            if(num[j]<min)      //找到s数组里面的min
             min = num[j];                
            }
        }
        bool *flag = new bool[min+1];
        memset(flag,false,min+1);   //并且开一个bool数组，并将其值均置为false

        for(int k=2;k<=min;k++)     //除数  遍历从2到min
        {
            if(flag[k]==false)
            {
                int p = 0;
                for(;p<s.size();p++) //被除数————即张数数组
                {
                    if(s[p]%k!=0)       //k不能整除其中一个张数 ，说明凡是k的倍数均不能整除任意一个张数，将k的倍数筛掉
                    {
                        int temp = 1;   
                        while( temp*k <= min )
                        {
                            flag[temp*k] = true;    //标记为true
                            temp++;
                        }
                        break;
                    }
                }
                if(p==s.size())
                return true;
            }
        }
        return false;
    }
};
```

