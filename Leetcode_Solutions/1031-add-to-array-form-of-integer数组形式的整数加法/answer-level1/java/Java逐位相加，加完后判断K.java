![image.png](https://pic.leetcode-cn.com/31e509a5497fb5d3d564a33a8ea13774b67e43a9f37540bb71849c48a5f0eb39-image.png)

```
    public List<Integer> addToArrayForm(int[] A, int K) {

        int carry = 0;// 进位
        // 加到A数组
        for (int i = A.length - 1; i >= 0; i--, K /= 10) {
            int temp = A[i] + K % 10 + carry;
            A[i] = temp % 10;
            carry = temp / 10;
            if (K == 0 && carry == 0) {
                break;
            }
        }
        List<Integer> list = new ArrayList<Integer>();
        // 若K为0，说明A数组的数长度更长
        if (K == 0) {
            if (carry != 0) {
                list.add(carry);
            }
            for (int num : A) {
                list.add(num);
            }
            // 否则，K更长
        } else {
            K += carry;
            int bit = (int) Math.log10(K) + 1;// 求得K的位数
            int[] head = new int[bit];
            for (int i = head.length - 1; i >= 0; i--, K /= 10) {
                head[i] = K % 10;
            }
            for (int num : head) {
                list.add(num);
            }
            for (int num : A) {
                list.add(num);
            }
        }
        return list;
    }
```
