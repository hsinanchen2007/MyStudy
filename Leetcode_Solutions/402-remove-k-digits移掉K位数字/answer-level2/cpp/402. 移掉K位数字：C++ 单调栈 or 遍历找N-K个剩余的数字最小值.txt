### 解题思路
经典思路：单调栈，单调递增的序列最小。
123一定小于132


```cpp
class Solution {
public:
    string removeKdigits(string num, int k)
    {
        string str;
        int m = num.size() - k;
        for (int i = 0; i < num.size(); i++) {
            if (i == 0) {
                str.push_back(num[i]);
                continue;
            }
            while (k && !str.empty() && str.back() > num[i]) {
                str.pop_back();
                k--;
            }

            str.push_back(num[i]);
        }
        str.resize(m);

        while (str.size() > 0 && str[0] == '0') {
            str.erase(str.begin());
        }

        if(str.empty()){
            return "0";
        }

        return str;
    }
};
```



自己的思路：
1.移掉K个数字等价于取N-K个数字，值最小；则意味着每次要在K+1的范围内取最小值 （N-（N-K）+1 = K+1）
2.i每次向前移动1，j则取上一个最小值的索引+1

以num = "1432219", k = 3为例
1）k=3，则实际应该在1432，4322，3221，2219中取4个值，但实际上
2）第一轮 1432 i=3，j=0 -> i=3,j =3 minindex = 0,minvalue =1
   第二轮 4322 i=4，j=1 -> i=4,j =4 minindex = 3,minvalue =2
   第三轮 21   i=5，j=4 -> i=5,j= 5 minindex = 5,minvalue =1
   第四轮 1    i=6, j=6 -> i=6, j=6 minindex = 6,minvalue =1


### 代码

```cpp
class Solution {
public:

    int charToInt(char c)
    {
        return c-'0';i
    }

    string removeKdigits(string num, int k) {
        if(num.empty()||k>=num.size()){
            return string("0");
        }

        string result;
        stringstream strstream;

        int begin = 0;
        bool falg = false;
        for(int i = 0;i<num.size();i++){
            
            if(i< k){               
                continue;
            }

            int minvalue = INT32_MAX;
            int minIndex =i-k;
            
            for(int j = begin;j<=i;j++){
                int value = charToInt(num[j]);
                if( value < minvalue ){
                    minvalue= value;
                    minIndex = j;

                }
            }

            
            if(!falg && strstream.str().empty() && minvalue == 0){
                
            }else{
                falg = true;
                strstream<<minvalue;
            }


            begin = minIndex+1;

        }
        strstream>>result;

        if(result.empty()){
            return string("0");
        }

        return result;
  
    }
};
```