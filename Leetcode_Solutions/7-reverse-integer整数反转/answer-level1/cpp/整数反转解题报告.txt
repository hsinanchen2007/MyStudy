更多题解：http://leetcodedoc.xuezhisd.top/index.html
## 题目解析

- 本题是一道模拟题，关键是对结果超出int32的情况的判断。

### 不确定性

- 明确末尾为0的情况处理

### 方法一：长整形法

#### 分析

- 直接利用取模法模拟即可

#### 思路

- 先利用取模法计算出结果，存储在长整型 int64中。
- 再去判断结果是否在int32范围内。

#### 注意

- int32 的最大值和最小值分别是 2^31-1(2147483647),  -2^31(-2147483648)
- 考虑负数

#### 知识点

- 取模
- 模拟
- int32范围
- 2，16进制表示法

#### 复杂度

- 时间复杂度O(1)
- 空间复杂度O(1)

#### 代码

```cpp
typedef long long lld;
const int IntMax= 0x7fffffff, IntMin = 0x80000000; // c++ 常量 INT32_MAX，INT32_MIN 也表示
// 0x7fffffff == 2^31-1, 0x80000000 = -2^31, 不明白可以探索二进制资料学习一下。

class Solution {
    lld getReverseLld(int x) 
    {
        lld res = 0; // 使用长整型防止溢出
        for(;x!=0;x/=10) res = res*10 + x%10;
        return res;
    }

public:
    int reverse(int x) {
        lld res = getReverseLld(x);
        if (res < IntMin || res > IntMax) return 0;
        return int(res);
    }
};

/*
0
-123
1111111111
123456778
2147483647
-2147483648
2147447412
-2147447412
-2147447413
*/
```

### 方法二：数组法

#### 分析

- 在上一题基础上加大难度，给出的初始值是int64，那么上方法一就不可以使用了，没有比int64更大的有符号整数了。
- 为了解决上述变形题型，我们用另一种方法解决本文的题目
- 题目的难点是在处理边界值，即结果超出int32范围的情况，如果能判出结果超出了范围，那么题目就解决了
- 初始值是int64的解法请读者自己思考

#### 思路

- 首先我们可以知道结果（绝对值）的长度
- 如果长度小于len(2147483647) = 10，那么肯定不超出范围
- 再来讨论长度=10的情况
- 拿结果绝对值与2147483647从高到低逐位比较

#### 注意

- 题目输入不可能是8463847412，-8463847412(不在int32范围内)
- 故也不可能出现翻转后变成2147483648
- 所以只要拿2147483647与翻转后的数组比较大小即可
- 出现前导0的情况，这里不影响结果
- 输入为负数的情况

#### 知识点

- 数组
- 模拟
- 字符串比较大小

#### 复杂度

- 时间复杂度O(1)
- 空间复杂度O(1)

#### 代码

```cpp
//
class Solution {
    vector<int> MaxArr;
    void initMaxArr()
    {
        for(int i=INT32_MAX;i>0;i/=10) MaxArr.insert(MaxArr.begin(),i%10);
        /*
        for (int i : MaxArr)
        {
            cout<<i<<" ";
        }
        cout<<endl;
        */
    }

    vector<int> getAbsReverseArr(int x)
    {
        vector<int> rArr;
        int sign=1;
        if(x<0)sign=-1;
        // 这里不能用直接取绝对值 x=INT32_MIN 时，-x 会越界
        for (; x!=0 ; x/=10) rArr.push_back(x%10*sign);
        return rArr;
    }

    int arr2Int(vector<int> arr, bool isNeg)
    {
        int res=0;
        for (int n : arr)res = res*10+n;
        return isNeg?-res:res;
    }

    bool isOutOfRange(vector<int> arr)
    {
        if(arr.size()<MaxArr.size())return false;
        int i=0;
        for (i = 0; i < MaxArr.size() && MaxArr[i]==arr[i]; ++i); // 比出第一个不相等的数
        if (i>=MaxArr.size())return false; // 都相等了，没有溢出

        return MaxArr[i]<arr[i]; // 目标数大就是溢出了
    }
public:
    Solution()
    {
        initMaxArr();
    }

    int reverse(int x) {
        auto rArr = getAbsReverseArr(x);
        if (isOutOfRange(rArr))return 0;
        return arr2Int(rArr, x<0);
    }
};

/*
0
1111111111
1000000000
12303000
-123
123456778
2147483647
-2147483648
2147447412
-2147447412
-2147447413
2147447413
*/
```

## 相关题目

- <https://leetcode-cn.com/problems/reverse-bits/>
- <https://leetcode-cn.com/problems/string-to-integer-atoi/>

