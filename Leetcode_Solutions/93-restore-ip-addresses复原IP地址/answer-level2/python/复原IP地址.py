#### 直觉

最朴素的解法是暴力法, 
_换而言之_，检查点可能的所有位置，并只保留有效的部分。在最坏的情况下，有`11`个可能的位置，因此需要$11 \times 10 \times 9
= 990$ 次检查。

可以通过以下两个概念来优化。

> 第一个概念是 _约束规划_。 

这意味着对每个点的放置设置一些限制。若已经放置了一个点，下一个点只有 `3` 种可能：1/2/3个数字之后。

这样做传播了_约束_ ，且减少了需要考虑的情况。我们只需要检测 $3 \times 3 \times 3 = 27$种情况，而非f $990$ 种。

> 第二个概念是 _回溯_。

我们假设已经放置了一或两个点使得无法摆放其他点来生成有效IP地址。这时应该做什么？ _回溯_。T也就是说，回到之前，改变上一个摆放点的位置。并试着继续。如果依然不行，则继续 _回溯_。
<br />
<br />


---
#### 方法一 ： 回溯(DFS)

这是一个回溯函数`backtrack(prev_pos = -1, dots = 3)` 的算法，该函数使用上一个放置的点 `prev_pos`
和待放置点的数量 `dots` 两个参数 :

*  遍历三个有效位置`curr_pos` 以放置点。
   * 检查从上一个点到现在点中间的部分是否有效 :
      * 是 :
        * 放置该点。
        * 检查全部 `3`个点是否放好:
            * 是 :
                * 将结果添加到输出列表中。
            * 否 :
                * 继续放下一个点 `backtrack(curr_pos, dots - 1)`。
        * 回溯，移除最后一个点。


<![image.png](https://pic.leetcode-cn.com/b70ef61b6de155c6dda496e4beaaa0c24cb2d5b24e75966d894e7333b3076a4e-image.png),![image.png](https://pic.leetcode-cn.com/77fc7f3013bf12aa449bc67124eb4e1f3348f07040df7b7aa89cb3178861cf32-image.png),![image.png](https://pic.leetcode-cn.com/e8b6b69963a4cdab7087167d89656d86ed02473d69e4e4955bb974390b718442-image.png),![image.png](https://pic.leetcode-cn.com/9c88a226f0fb3dd9d6b4f0ba1d6d049a6ccd7fe8874da9daa6aef05f47a084de-image.png),![image.png](https://pic.leetcode-cn.com/81a400744af0d42eec9e8778fc57ccfbc457624ab1e13c8c0636ab661af70f4c-image.png),![image.png](https://pic.leetcode-cn.com/fa5d3e92415675266b731bd3ecedd73c33cd3490280b941dc53388a4a8252da4-image.png),![image.png](https://pic.leetcode-cn.com/166490a0ce9e28aca0d06eca4f843ae8f51f123f868f3c9d4fc004f83f2e4375-image.png),![image.png](https://pic.leetcode-cn.com/02ffcbf871e2bf70d26af7d8c1dca1711f91f62f536960bfe27a09ae55a0b93c-image.png),![image.png](https://pic.leetcode-cn.com/76236bd3c6fbe5082d1d5fa82870fcdca149eb7fca9c44e2fb564f10e94fff90-image.png),![image.png](https://pic.leetcode-cn.com/54330520fc4a1481d44ae6da4e58e019fef23ea530697513c7ccb22701115e5d-image.png),![image.png](https://pic.leetcode-cn.com/765058e05823a1d775b19a2f4d1778d3fd67532011abb432dd7f23def8459d1b-image.png),![image.png](https://pic.leetcode-cn.com/ca87c54b3c6928da687bdc3a9b1e3bd603e73e65fe4b5b1085cbc5613572d75b-image.png),![image.png](https://pic.leetcode-cn.com/305d46d5ef1e56a2ec847f7bbe97a7757c89252e3b2370282338e725f27a6ad1-image.png),![image.png](https://pic.leetcode-cn.com/96f21bff963f6ccf6fed2494361332ea5ed56c39dc2167088920b9b07c9184a7-image.png),![image.png](https://pic.leetcode-cn.com/a97100c69886f77cd7e39b63bbd2e5da25fae5abf9b9015c5d1af085370c5896-image.png),![image.png](https://pic.leetcode-cn.com/1844c0cd0b28a5c97c7fb07b6a620041b56331270c935515bca6c574248f76bd-image.png),![image.png](https://pic.leetcode-cn.com/0f7785cf60e6c0172e72f5c1be2039290ce8644306e92b2d806caf9658df61dd-image.png),![image.png](https://pic.leetcode-cn.com/92c4092afce624267f921522979b7c78f059f08f37560b3bc403bcce92697abf-image.png),![image.png](https://pic.leetcode-cn.com/1c7149759eb9bd7a3c3e4c1a50c0992dd647570b768a553529990b7092fd4a4d-image.png),![image.png](https://pic.leetcode-cn.com/22d99f93ff682b45b18c9380dc4b752395d27bae528fc0b5f251d2241d0d6aaa-image.png),![image.png](https://pic.leetcode-cn.com/ede44163c5a71176a6a397ad9677843660b3401ffdbbfc0fa04b662b57814cca-image.png),![image.png](https://pic.leetcode-cn.com/179d7d352cda8c2703f068326cfc4e4d8591cef719245ef18ac676f7d2cafb8e-image.png)>

```Java [solution 1]
class Solution {
  int n;
  String s;
  LinkedList<String> segments = new LinkedList<String>();
  ArrayList<String> output = new ArrayList<String>();

  public boolean valid(String segment) {
    /*
    Check if the current segment is valid :
    1. less or equal to 255      
    2. the first character could be '0' 
    only if the segment is equal to '0'
    */
    int m = segment.length();
    if (m > 3)
      return false;
    return (segment.charAt(0) != '0') ? (Integer.valueOf(segment) <= 255) : (m == 1);
  }

  public void update_output(int curr_pos) {
    /*
    Append the current list of segments 
    to the list of solutions
    */
    String segment = s.substring(curr_pos + 1, n);
    if (valid(segment)) {
      segments.add(segment);
      output.add(String.join(".", segments));
      segments.removeLast();
    }
  }

  public void backtrack(int prev_pos, int dots) {
    /*
    prev_pos : the position of the previously placed dot
    dots : number of dots to place
    */
    // The current dot curr_pos could be placed 
    // in a range from prev_pos + 1 to prev_pos + 4.
    // The dot couldn't be placed 
    // after the last character in the string.
    int max_pos = Math.min(n - 1, prev_pos + 4);
    for (int curr_pos = prev_pos + 1; curr_pos < max_pos; curr_pos++) {
      String segment = s.substring(prev_pos + 1, curr_pos + 1);
      if (valid(segment)) {
        segments.add(segment);  // place dot
        if (dots - 1 == 0)      // if all 3 dots are placed
          update_output(curr_pos);  // add the solution to output
        else
          backtrack(curr_pos, dots - 1);  // continue to place dots
        segments.removeLast();  // remove the last placed dot 
      }
    }
  }

  public List<String> restoreIpAddresses(String s) {
    n = s.length();
    this.s = s;
    backtrack(-1, 3);
    return output;
  }
}
```

```Python [solution 1]
class Solution:
    def restoreIpAddresses(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        def valid(segment):
            """
            Check if the current segment is valid :
            1. less or equal to 255      
            2. the first character could be '0' 
               only if the segment is equal to '0'
            """
            return int(segment) <= 255 if segment[0] != '0' else len(segment) == 1
            
        def update_output(curr_pos):
            """
            Append the current list of segments 
            to the list of solutions
            """
            segment = s[curr_pos + 1:n]
            if valid(segment):
                segments.append(segment)
                output.append('.'.join(segments))
                segments.pop()    
            
        def backtrack(prev_pos = -1, dots = 3):
            """
            prev_pos : the position of the previously placed dot
            dots : number of dots to place
            """
            # The current dot curr_pos could be placed 
            # in a range from prev_pos + 1 to prev_pos + 4.
            # The dot couldn't be placed 
            # after the last character in the string.
            for curr_pos in range(prev_pos + 1, min(n - 1, prev_pos + 4)):
                segment = s[prev_pos + 1:curr_pos + 1]
                if valid(segment):
                    segments.append(segment)  # place dot
                    if dots - 1 == 0:  # if all 3 dots are placed
                        update_output(curr_pos)  # add the solution to output
                    else:
                        backtrack(curr_pos, dots - 1)  # continue to place dots
                    segments.pop()  # remove the last placed dot
        
        n = len(s)
        output, segments = [], []
        backtrack() 
```


**复杂度分析**

* 时间复杂度 : 如上文所述，需要检查的组合不多于`27`个。
* 空间复杂度 : 常数空间存储解，不多于`19` 个有效IP地址。
![image.png](https://pic.leetcode-cn.com/3baa385fecae6239495c19c88a279f4b76752a7a089fabdf15685e829b8e0a73-image.png){:width=500px}

