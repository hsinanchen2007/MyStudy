### 解题思路
(同餘定理運用)
★★ 1、『累加過程』中: 當A 與 A + (B + C)有相同餘數時，表示: 在累加的過程中必定是加了個(除數K的倍數)值 =>(B + C) % K = 0
  ~ 【注意】上述思想中，當同餘出現2次以上時，存在~>兩兩配對之組合關係，解釋如下:
  ~    假設: A、(A+B) 同餘   則 (B % K) =0《一種可能性》
  ~  又出現: (A+B+C)  也同餘 則 (C % K) =0 且 (B+C) % K =0《兩種可能性》
  ~  又出現: (A+B+C+D)也同餘 則 (D % K) =0 且 (C+D) % K =0 且 (B+C+D) % K =0《三種可能性》
  ~  又出現: ...
### 代码

```python3
class Solution:
    def subarraysDivByK(self, A: List[int], K: int) -> int:
        pre_sum, result = 0, 0
        dic = {0: 1}  # initial

        for val in A:
            pre_sum = (pre_sum + val) % K  # 累加並對 K取餘
            if pre_sum in dic:  # 判斷是否在字典內，即有(同餘的值)
                res += dic[pre_sum]  # 更新結果
            # key不存在 則默認val=0 + 1 、key在 則 val +=1
            # ~>若再下次出現"同餘"時，"同餘"出現3次，會有兩種可能性
            # ~>若再下次出現"同餘"時，"同餘"出現4次，會有三種可能性...
            dic[pre_sum] = dic.get(pre_sum, 0) + 1

        return result
```