其实仔细观察就是个数学问题, 附上代码解释:

```go []
func findContinuousSequence(target int) [][]int {
	var a [][]int
	i := 2 // 起始组

	for {
		// 该组起始数字, 这个公式的来源: 比如 2 个, 那么 2x + 1 = target,
		// 其实就是 x + 0 + x + 1 = target, 所以就是 2x + (0, 1 组成的等差数列) = target,
		// 那么对于 i 个数组成的组就是: d * i + (i - 1) * i / 2 = target
		d := (target - (i-1)*i/2) / i
		m := (target - (i-1)*i/2) % i // 余数
		if d == 0 {                   // 终止条件
			break
		}
		if d != 0 && m > 0 { // 如果余数不为 0 需要跳过继续
			i++
			continue
		}
		var e []int
		for j := 0; j < i; j++ {
			e = append(e, d+j)
		}

		a = append([][]int{e}, a...) // 插入之前, 组元素多的一定排前面
		i++
	}

	return a
}
```
```java []
class Solution {
    public int[][] findContinuousSequence(int target) {
        List<int[]> res = new LinkedList<>(); // 此处使用 LinkedList 而不是 ArrayList , 因为需要头插入
        int i = 2; // 起始组

        for (;;) {
            // 该组起始数字, 这个公式的来源: 比如 2 个, 那么 2x + 1 = target,
            // 其实就是 x + 0 + x + 1 = target, 所以就是 2x + (0, 1 组成的等差数列) = target,
            // 那么对于 i 个数组成的组就是: d * i + (i - 1) * i / 2 = target
            int d = (target - (i - 1) * i / 2) / i; // 该组起始数字
            int m = (target - (i - 1) * i / 2) % i; // 余数

            if (d == 0) { // 终止条件
                break;
            }

            if (d != 0 && m > 0) { // 如果余数不为 0 需要跳过继续
                i++;
                continue;
            }

            int[] e = new int[i];
            for (int j = 0; j < i; j++) {
                e[j] = d + j;
            }
            res.add(0, e); // 头插入, 组元素多的一定排前面
            i++;
        }

        return res.toArray(new int[0][]);
    }
}
```
