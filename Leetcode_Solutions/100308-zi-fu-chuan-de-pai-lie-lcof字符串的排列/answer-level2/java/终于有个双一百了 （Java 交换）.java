很明显，这道题是道全排列的题，同 [LeetCode 47. 全排列II](https://leetcode-cn.com/problems/permutations-ii/) 一模一样，只不过将数字改为了字符而已。

全排列问题的解法有很多，详情可见 [维基百科：全排列生成算法](https://zh.wikipedia.org/wiki/%E5%85%A8%E6%8E%92%E5%88%97%E7%94%9F%E6%88%90%E7%AE%97%E6%B3%95)，但是个人觉得还是**交换法**更为简单易懂。

交换法，简单来说就是两两交换，从而生成一个新的排列。

以 `[1,2,3]` 为例：

```
[1, 2, 3]

[2, 1, 3]
[2, 3, 1]
[3, 2, 1]
[3, 1, 2]
[1, 3, 2]
```

---

话不多说，贴上代码：

```java
class Solution {
    List<String> list = new ArrayList<>();
    public String[] permutation(String s) {
        char[] ori = s.toCharArray();

        helper(ori, 0);
        return list.toArray(new String[0]);
    }
    
    private void helper(char[] all, int index) {
        if (index == all.length) {
            String s = new String(all);
            list.add(s);
        }
        
        for (int i = index; i < all.length; i++) {
            if (i == index) {   // 同一个下标，无需交换
                helper(all, index+1);
                continue;
            }
            
            int k;
            for (k = i-1; k >= index; k--) {    // 剔除重复
                if (all[k] == all[i])   break;
            }
            
            if (k != index-1) continue;
            
            swap(all, i, index);
            helper(all, index+1);
            swap(all, i, index);
        }
    }
    
    private void swap(char[] all, int i, int j) {
        char tmp = all[i];
        all[i] = all[j];
        all[j] = tmp;
    }
}
```

![image.png](https://pic.leetcode-cn.com/bbf9f4825d21f49bb48e9faac918da01492475d561e359574488289cebe09cab-image.png)
