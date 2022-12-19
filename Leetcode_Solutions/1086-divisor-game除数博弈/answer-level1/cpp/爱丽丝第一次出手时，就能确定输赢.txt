### 解题思路
  对于每一个确定的N，爱丽丝第一次出手的时候就能确定自己是输还是赢，不存在几个回合后才看出输赢的情况。证明如下：
  当N=1时，爱丽丝必输。
  当N>1时，假设第i-1次之前游戏结果确定(i∈[2,N])，则在第i次时，对于i的任意约数x，i-x∈[1,i)，i-x能确定输赢，即i能确定输赢。 

  综上，这个“除数博弈”游戏并没有什么意思，因为从一开始，游戏的输赢就以确定。

  解题时，将N之前的结果都计算出来，对于每一个结果i，计算方法为：遍历i的所有约数j，如果存在result[i-j]，使得result[i-j]为False，此时result[i]为True。如果不存在这么一个j，则result[i]为False。
### 代码

```python3
class Solution:
    def divisorGame(self, N: int) -> bool:
      result = [False for i in range(N + 2)]
      result[1] = False
      for i in range(2, N + 1):
        temp = False
        for j in range (1, i // 2 + 1):
          if i % j == 0:
            if not result[i - j]:
              temp = True
              break;
        result[i] = temp
      return result[N]
```

```cpp
class Solution {
public:
    bool divisorGame(int N) {
    bool result[N + 1] = {false};
    if (N == 1)
      result[1] = false;
    for (int i = 2; i <= N; ++i){
      bool temp = false;
      for (int j = 1; j < i; ++j){//可以优化为j < i / 2>
        if (i % j == 0){
          if (result[i - j] == false){
            temp = true;
            break;
          }
        }
      }
      result[i] = temp;
    }
    
    return result[N];
    }
};
```