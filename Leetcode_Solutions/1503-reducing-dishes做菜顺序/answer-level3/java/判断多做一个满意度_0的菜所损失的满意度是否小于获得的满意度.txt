### 解题思路
1. 所有 满意度 >= 0 的菜全做，从满意度低的做到满意度高的
2. 每做一个 满意度 <0 的菜，总满意度结果为：当前总满意度+（所有需要做的菜的满意度的和）
3. 对与每个 满意度 <0 的菜，总满意度升则做，降低则不做


### 代码


```java []
public int maxSatisfaction(int[] satisfaction) {

        Arrays.sort(satisfaction);
        
        int result = 0;
        int pnum = 0;
        int index = 1;

        for (int i : satisfaction) {
            if (i >= 0) {
                // 所有满意度非负的菜全做的满意度
                result = result + i * index++;
                // 所有满意度非负的满意度和
                pnum += i;
            }
        }

        // 每做一个满意度为负的菜多损失的满意度
        int nnum = 0;
        
        for (int i = satisfaction.length - 1; i >= 0; i--) {
            if (satisfaction[i] < 0) {
                // 如果做一个满意度为负的菜后，损失的满意度<获得的满意度,则做该菜
                if (-(satisfaction[i] + nnum) <= pnum) {
                    nnum += satisfaction[i];
                    result = result + pnum + nnum;
                }
            }
        }

        return result;
    }
```
```java []
public int maxSatisfaction(int[] satisfaction) {

        Arrays.sort(satisfaction);

        int result = 0;
        
        // 每多做一道菜，还需要将原来需要做的菜再做一遍
        int sum = 0;

        for (int i = satisfaction.length - 1; i >= 0; i--) {
            // 记录做过的菜的和，做完该菜后获得的满意度<0,直接break
            sum += satisfaction[i];
            if (sum < 0) {
                break;
            }
            result += sum;
        }

        return result;
    }
```
