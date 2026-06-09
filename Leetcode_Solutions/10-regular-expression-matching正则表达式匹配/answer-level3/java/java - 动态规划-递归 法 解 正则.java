#  【算法】正则匹配:java - 递归算法 - 动态规划 

[TOC]

## 1、题目

给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。

```
'.' 匹配任意单个字符
'*' 匹配零个或多个前面的那一个元素
```

所谓匹配，是要涵盖 整个 字符串 s的，而不是部分字符串。

说明:

- s 可能为空，且只包含从 a-z 的小写字母。

- p 可能为空，且只包含从 a-z 的小写字母，以及字符 . 和 *。

**示例1:** 



```
输入:
s = "aa"
p = "a"
输出: false
解释: "a" 无法匹配 "aa" 整个字符串。
```

**示例 2:**

```
输入:
s = "aa"
p = "a*"
输出: true
解释: 因为 '*' 代表可以匹配零个或多个前面的那一个元素, 在这里前面的元素就是 'a'。因此，字符串 "aa" 可被视为 'a' 重复了一次。
```

**示例 3:**

```
输入:
s = "ab"
p = ".*"
输出: true
解释: ".*" 表示可匹配零个或多个（'*'）任意字符（'.'）。
```

**示例 4:**

```
输入:
s = "aab"
p = "c*a*b"
输出: true
解释: 因为 '*' 表示零个或多个，这里 'c' 为 0 个, 'a' 被重复一次。因此可以匹配字符串 "aab"。

```

**示例 5:**

```
输入:
s = "mississippi"
p = "misisp*."
输出: false
```

## 2、递归算法

### 第零步： 题目整理

看到这个题目的时候，分析题目，方法的基本架构是这样的。

```java
  	  /**
	   * @param s字符串abc这种
	   * @param p 正则串"a*a*a*a*a*a*a*a*a*a*c"
	   * @return 返回是否能匹配的上
	   */
	  public boolean isMatch(String s, String p);
```

这里就是比较s (字符串) 是否符合p(pattern)的规则。pattern里边有两种特殊符号：`.`、`*`

### 第一步：不考虑特殊符号：

```java
 public boolean isMatch(String s, String p){
     if(s.equals(p)) return true;
 }
```

### 第二步：考虑`.` -递归的思路：

这个时候，我们不能直接比较了，但是.代替的是任何一个符号，为了下边的顺利进行，我们用**递归**的方法一个字符一个字符的比较。

就比如说 传入的字符串是`abcd` 正则式：`ab.d`的时候， 

我们在`isMatch`方法中先比较 `s` 变量的 第一个字符 `（a）`和 `p`变量的第一个字符`（a）`是否相等。

- 如果不想等，我们再看看p的第一个首字母，如果是`.`也认为s的首字母和d的首字母相等
- 如果依然不等，那我们就认为这两个字符串不匹配
- 如果相等，那我们就比较剩下的字符串 `bcd` 和表达式 `b.d`是否相等。若首字母匹配，剩下的字节匹配我们就认为这两个字符串匹配。

就比如我们按照上边的`abcd` `ab.d`比较的流程展示一下：

1. `abcd` 的`a` 和`ab.d`的 `a`匹配，然后比较 `bcd` 和`b.d`是否匹配
2. `bcd` 的`b` 和`b.d`的 `b`匹配，然后比较 `cd` 和`.d`是否匹配
3. `cd` 的`c` 和`.d`的 `.`匹配，然后比较 `d` 和`d`是否匹配
4. `d` 和`d`相等，那我们就认为 `d`和`d`匹配

------



5. 因为`d`和`d`匹配，`cd` 的`c` 和`.d`的 `.`匹配 所以我们认为`cd` 和`c.`匹配
6. 因为`cd` 和`c.`匹配，`bcd` 的`b` 和`b.d`的 `b`匹配 所以我们认为`bcd` 和`b.d`匹配
7. 因为`bcd` 和`b.d`匹配，`abcd` 的`a` 和`ab.d`的 `a`匹配 所以我们认为`abcd` 和`ab.d`匹配

上边的过程看起来可能有点懵，下边从代码的角度来解析一下:

```java
 public boolean isMatch(String s ,String p) {
   //这个是第一步的思路不多解
   if(s.equals(p))return true;
   if(p.length()==0) {return s.length()==0;}
   //判断第一个字符，如果第一个字符相等，或者是一个点
   Boolean firstMatch = s.length()>0&&p.length()>0&&(s.subSequence(0, 1).equals(p.substring(0,1))||p.charAt(0)=='.');
   //判断
   return firstMatch && isMatch(s.substring(1), p.substring(1));
 }
```

-   `Boolean firstMatch`申明变量，判断第一个字符是否相等
-   `s.length()>0&&p.length()>0`判断两个字符串是否为空，如果为空，会返回`false`，进行短路操作，防止下一步报错。
- `(s.subSequence(0, 1).equals(p.substring(0,1))||p.charAt(0)=='.');` s的第一个字母和p的第一个字母是否相等，如果不想等，p的第一个字母是`.`也算是相等。
- `return firstMatch && isMatch(s.substring(1), p.substring(1));`如果首字母不等，直接短路返回`false`,如果相等，把剩下的字符串当成新的字符串继续进行比较

### 第三步：考虑`*`

因为`*`代表的是前一个字母可能是有零个，一个或者是多个

> eg:
>
> 输入:
> `s = "aab"`
> `p = "c*a*b"`
> 输出: true
> 解释: 因为 '*' 表示零个或多个，这里 'c' 为 0 个, 'a' 被重复一次。因此可以匹配字符串 "aab"

所以检测到第二位是`*`的时候，需要两种处理方式，一种是认为`*`代表多，另一种是认为`*`代表0

```java
 public boolean isMatch(String s ,String p) {
   if(p.length()==0) {return s.length()==0;}
     if(s.equals(p))return true;
     Boolean firstMatch = s.length()>0&&p.length()>0&&(s.subSequence(0, 1).equals(p.substring(0,1))||p.charAt(0)=='.');
            
//=============================*的处理方式===========
      if(p.length()>=2&&p.charAt(1)=='*') {//取值前进行短路处理
                  //判断有星星的时候,判断s没有*前面的哪个值，或者是如果有的话，就县判断一下第一个值一样不一样，第一个值一样的话，就判断紧接的下一个能不能匹配上。
          return isMatch(s.toString(),p.substring(2)) || (firstMatch&&isMatch(s.substring(1), p.toString()));
      }
//==========================================================================     
     return firstMatch && isMatch(s.substring(1), p.substring(1));
 }
```

-  `if(p.length()>=2&&p.charAt(1)=='*') {`//取值前进行判断，如果最后一位的话短路处理，不进入判断
     -  `return isMatch(s.toString(),p.substring(2)) || (firstMatch&&isMatch(s.substring(1), p.toString()))`;   --  返回两种情况，先考虑`*`是不是0的意思，如果0后续匹配不上，`*`代表多个的情况
-   `isMatch(s.toString(),p.substring(2))` 如果是0的话，直接跳过这个首字母和`*`进行接下来的比较，
     -  `abc` 和`z*abc`这个时候直接跳过`z`和`*`进行剩下的比较。
-   `firstMatch&&isMatch(s.substring(1), p.toString())` 比较第一个字符是否相等，如果不等，再多的`*`也没用，如果相等的话，就字符串抛开首字母，接着比较
     -  `aaabc`和`a*bc `先比较 第一个字符串的`a`和第二个字符串的`a`是否相等
     -  接着比较`aabc`和`a*bc`
     -  然后比较`abc`和`a*bc`
     -  最后比较 `bc`和`a*bc`这个时候就会在`isMatch(s.toString(),p.substring(2))` 这个分支返回true

### 第四步：完成与总结

理论上上边第三步基本能够完成这个题目，但是众所周知，递归对资源的消耗非常大。

我们在方法上加一行日志：查看一共调用了多少次

```java
//...
  System.out.println(i+++". s:\""+s+"\"  p:\""+p+"\"");
 Boolean firstMatch = s.length()>0&&p.length()>0&&(s.charAt(0)==p.charAt(0)||p.charAt(0)=='.');
//...
```



传入参数为：`"aaaaaaaaaaaaab", “a*a*a*a*a*a*a*a*a*a*db"`

输出日志:

```
0. s:"aaaaaaaaaaaaab"  p:"a*a*a*a*a*a*a*a*a*db"
1. s:"aaaaaaaaaaaaab"  p:"a*a*a*a*a*a*a*a*db"
2. s:"aaaaaaaaaaaaab"  p:"a*a*a*a*a*a*a*db"
3. s:"aaaaaaaaaaaaab"  p:"a*a*a*a*a*a*db"
4. s:"aaaaaaaaaaaaab"  p:"a*a*a*a*a*db"
5. s:"aaaaaaaaaaaaab"  p:"a*a*a*a*db"
6. s:"aaaaaaaaaaaaab"  p:"a*a*a*db"
7. s:"aaaaaaaaaaaaab"  p:"a*a*db"
8. s:"aaaaaaaaaaaaab"  p:"a*db"
9. s:"aaaaaaaaaaaaab"  p:"db"
10. s:"aaaaaaaaaaaab"  p:"a*db"
....
```

这个只是开始，我们看结束的时候，一共执行了多少行

```
....
1314598. s:"b"  p:"db"
1314599. s:"b"  p:"a*a*a*a*a*a*a*a*a*db"
1314600. s:"b"  p:"a*a*a*a*a*a*a*a*db"
1314601. s:"b"  p:"a*a*a*a*a*a*a*db"
1314602. s:"b"  p:"a*a*a*a*a*a*db"
1314603. s:"b"  p:"a*a*a*a*a*db"
1314604. s:"b"  p:"a*a*a*a*db"
1314605. s:"b"  p:"a*a*a*db"
1314606. s:"b"  p:"a*a*db"
1314607. s:"b"  p:"a*db"
1314608. s:"b"  p:"db"
false
```

进行了一百多万次查询，我们理论上应该在这里进行优化，就是当参数已经比过了，就不再进行查询。



## 3、动态规划

### 3.1 自上而下的算法

我们将递归的代码进行一下优化，主要就是添加一个值，用来标记这两个传入参数是否比过，如果比过了，就不进行接下来的递归。

为什么这么多次呢？我们可以简化一下参数，看看什么蹊跷，输入的值为`abc`,`a*a*b`

输出为：

```
0. s:"abc"  p:"a*a*b"
1. s:"abc"  p:"a*b"
2. s:"abc"  p:"b"
3. s:"bc"  p:"a*b"
4. s:"bc"  p:"b"
5. s:"bc"  p:"a*a*b"
6. s:"bc"  p:"a*b"
7. s:"bc"  p:"b"
false
```

可以看到 3，4 和6，7的输入参数完全一致，其实没必要进行重复计算的

所以我们执行完3，4之后，将其存放起来，然后进入递归的时候，判断一下是否这两个字符串是否比较过，如果比较过，就直接返回结果。

先来看示例：

```java
//先定义一个枚举类型，将来定义数组的时候，用得到
enum Result{
	TRUE,FALSE;
}
```
备忘录算法的核心：` Result[][] memo`来记住是否每个运算结果的答案

```java
public class solution{
    Result[][] memo ;//为什么要用Result而不直接用boolean类型呢？因为boolean类型的默认值不是空，我们没办法知道这个值是不是已经遍历过了。
    int index = 0;
    public boolean isMatchDP2(String s,String p) {
        
        memo  = new Result[s.length()+1][p.length()+1];
		return dp(0,0,s,p);  
    }
}	
```

dp是核心递归算法，如果在memo中有记录的话，就直接返回结果，如果没有比较过的话，就不用重新比较。

```java
  public boolean dp(int i,int j ,String s,String p) {
		  if(memo[i][j]!=null)return memo[i][j]==Result.TRUE;//这里就是为什么不用boolean二位数组的原因，如果用boolean的话，每次不是true就是false不会有null
		  boolean ans;
		  if(j==p.length()) {//如果超过了p的匹配位数，s也超出的话，就直接返回
			  ans= i==s.length();
			  memo[i][j]=ans?Result.TRUE:Result.FALSE;
			  return ans;
		  }
		  boolean firstMatch = j<p.length()&&i<s.length()&&(s.charAt(i)==p.charAt(j)||p.charAt(j)=='.');//这个算法和之前的递归算法基本上一致，只不过原来是截取字符串，现在是取不同的位数
		  if(j<(p.length()-1) &&p.charAt(j+1)=='*') {//基本上就是将递归的算法翻译了一下，然后返回
			  ans = dp(i,j+2,s,p)||(firstMatch&&dp(i+1,j,s,p));
		  }
		  else {
			  ans = firstMatch&& dp(i+1,j+1,s,p);
		  }
		  memo[i][j]=ans?Result.TRUE:Result.FALSE;//拿到结果后，记录在备忘录里边。
		  System.out.println(a+++". i:\""+i+"\"  j:\""+j+"\"      "+ memo[i][j]);//没用，就是为了看看同样的操作具体执行了多少行。
		  return ans;
	  }
	
```

这里和递归算法有一个概念上的区别，其实区别不大，递归算法比较`abc a*bc`的时候，先比较a和`a*`然后比较bc和bc,带备忘录（memo）的算法是根据下标来计算的，先比较abc的第一位是否相等，然后在比较`a*bc`第三位和`abc`的第二位是否相等。dp算法中主要就是用来判断，这两个下标能不能比。

我们再执行以下上边的的两个参数，看看需要比较多少次：传入参数为：`"aaaaaaaaaaaaab", “a*a*a*a*a*a*a*a*a*a*db"`

```
0. i:"0"  j:"18"      FALSE
1. i:"1"  j:"18"      FALSE
2. i:"2"  j:"18"      FALSE
3. i:"3"  j:"18"      FALSE
4. i:"4"  j:"18"      FALSE
5. i:"5"  j:"18"      FALSE
6. i:"6"  j:"18"      FALSE
7. i:"7"  j:"18"      FALSE
8. i:"8"  j:"18"      FALSE
9. i:"9"  j:"18"      FALSE
10. i:"10"  j:"18"      FALSE
...
130. i:"9"  j:"0"      FALSE
131. i:"8"  j:"0"      FALSE
132. i:"7"  j:"0"      FALSE
133. i:"6"  j:"0"      FALSE
134. i:"5"  j:"0"      FALSE
135. i:"4"  j:"0"      FALSE
136. i:"3"  j:"0"      FALSE
137. i:"2"  j:"0"      FALSE
138. i:"1"  j:"0"      FALSE
139. i:"0"  j:"0"      FALSE
```

一共需要比较139次，基本上效率提高近万倍。



### 3.2 自底向上 的算法

> 这儿我不是很熟，可能有问题。

这个的思路和上边的算法比较类似，不过是从后往前的遍历，如果这样的话，比较i的时候 已经知道`i+1`到底匹配不，就不需要递归了。

```java
  public boolean isMatchDP3(String s,String p) {
		  boolean dp[][] = new boolean[s.length()+1][p.length()+1];
		  //先默认“”，“”是匹配的
		  dp[s.length()][p.length()]=true;
		  
		  for (int i =s.length(); i >=0 ; i--) {
			for(int j=p.length()-1;j>=0;j--) {
				boolean firstMatch =i<s.length()&&j<p.length()&&
						(s.charAt(i)==p.charAt(j)||p.charAt(j)=='.');
				if(j+1<p.length()&&p.charAt(j+1)=='*') {
					dp[i][j] = dp[i][j+2]||firstMatch&&dp[i+1][j];
				}else {
					dp[i][j] = firstMatch&&dp[i+1][j+1];
				}
			}
		}
		  
		  return dp[0][0];
	  }
	
```



