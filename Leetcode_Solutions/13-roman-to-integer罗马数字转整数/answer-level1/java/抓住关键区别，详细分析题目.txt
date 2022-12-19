# 抓住关键点，详细分析题目


> **说明：写本题解一方面是给自己备忘，另一方面是分享给没有思路的同学，所以内容很基础。大佬们不喜勿喷，请绕道行走。🤣**

## 最基础情况
试想一下，假如没有那几条特殊的规则，就是最简单的文字转换。那像`XIV`这样就可以直接转换为`10`+`1`+`5`=`16`

**注意：这是我们的整体思路，即字符的转换。**

## 特殊情况
现在我们得知有三大种、六小种特殊情况，即：

* `I(1)` 和 `V(5)` 或 `X(10)` 组成 `IV(4)` 和 `IX(9)`

* `X(10)` 和 `L(50)` 或 `C(100)` 组成 `XL(40)` 和 `XC(90)`

* `C(100)` 和 `D(500)` 或 `M(1000)` 组成 `CD(400)` 和 `CM(900)`

我把他们写成这样的形式相信大家一眼就可以看出来这其中的**规律：当右边的数是左边的数5倍或10倍的时候，左边的数就去相反数与其相加即可。** 

举个例子，`IV`其中`V(5)`是`I(1)`的五倍，那么这时候两者在一起，只需将`I`取值为相反数-1，然后再相加即可。那么`XIV`也就可以写成`10`+`-1`+`5`=`14`**（可以看看后记哦）**

## 需要注意的地方
因为需要用到前一个和后一个值做比较，所以需要考虑下标**是否越界**的问题，因此在遍历字符串时要在倒数第二个地方结束，即`i`只能取值`0 <= i < s.length()-1`。最后再加上字符串最后一位的值。

## Java代码
```Java
class Solution {
    public int romanToInt(String s) {
        HashMap<Character,Integer> map=new HashMap<Character,Integer>();//使用map把他们对应存储起来
        map.put('I',1);
        map.put('V',5);
        map.put('X',10);
        map.put('L',50);
        map.put('C',100);
        map.put('D',500);
        map.put('M',1000);
        
        int res=0;          //存放结果
        int current=0;     //第一个值
        int next=0;       //后一个值
        
        for(int i=0;i<s.length()-1;++i){        //注意这里的s.length()-1是为了防止下标越界
            current=map.get(s.charAt(i));
            next=map.get(s.charAt(i+1));

            if(next/current==5||next/current==10){    //如果满足后一个是前一个5倍或10倍
                res-=map.get(s.charAt(i));            //结果减掉当前值（相当于加了相反数）
            }else{
                res+=map.get(s.charAt(i));            //否则加上当前值
            }
        }
        
        res+=map.get(s.charAt(s.length()-1));        //最后再加上字符串末尾的值
        
        return res;
    }
}
```

## 后记
**这里能有人会问，那万一是 `V(5)` 和 `L(50)` 放在一起呢？这也是十倍的关系啊！说实话一开始我也没有想到这一点，就是在写这篇文章的时候才发现的。但事实上这是不符合题目假设的，因为题目说明除了6种情况外，小的数必须在大的数右边。**

**但本着杠精的思想，我提交了测试，发现LeetCode返回的结果是`VL`=45，这让我很惊讶！于是我大胆尝试测试了一个`V(5)`和`C(100)`组合是什么结果，结果更让我惊讶的是`VC`=95，但按照我之前写的思路，应该是`VC`=105。这样看来我萌生了一个大胆的想法，只要是左边的数比右边的数小，那么左边的数就要变成相反数，基于这一想法我修改代码，再次提交。再次惊讶，竟然运行时间比之前减小了20%。咱也不知道为啥，咱也不敢问。多半是判断条件减少了所以快了吧。不知道这种小数在大数左边的到底该怎么判定，不该返回`0`或者错误吗？😂**

**这是修改后的代码（就改了个判断条件）**
```Java
class Solution {
    public int romanToInt(String s) {
        HashMap<Character,Integer> map=new HashMap<Character,Integer>();
        map.put('I',1);
        map.put('V',5);
        map.put('X',10);
        map.put('L',50);
        map.put('C',100);
        map.put('D',500);
        map.put('M',1000);
        
        int res=0;
        int current=0;
        int next=0;
        
        for(int i=0;i<s.length()-1;++i){
            current=map.get(s.charAt(i));
            next=map.get(s.charAt(i+1));
            if(next>current){
                res-=map.get(s.charAt(i));
            }else{
                res+=map.get(s.charAt(i));
            }
        }
        
        res+=map.get(s.charAt(s.length()-1));
        
        return res;
    }
}
```

### 欢迎大家讨论这个`VC`的问题