先找到比总数小的前一行数组排满是什么情况，插入数组,
每一层排满,数组的排序都是这样的
m初始为0，q初始为1； 
起始
m*n+q
末尾
(m+q)*n
在每一次循环结束时，让m+=q，q++可以拿到下次层的m和q的值，具体情况是我自己推导了一下，
不知道有没有更简单的公式。
因为while循环结束之后，count肯定比k要大，所以定义了一个sum来存储之前的count值，
为避免q和m多一次运算，在循环里一旦count>=k时就直接break。
接着，先让x初始为数组的起始值，将之放入数组中，
然后让k-sum拿到多出来的值，公式拿到x也就是按递增排序的需要往数组里添加的数最后得到的结果返回
```
 public int[] distributeCandies(int k, int n) {
        int[] a = new int[n];
        int m = 0;
        int q = 1;
        int count = 0;
        int sum = 0;
        while (count < k) {
            sum = count;
            count = (m * n + q + (m + q) * n) * n >> 1;
            if (count >= k) break;
            m = m + q;
            q++;
        }
        
            q -= 1;
            m = m - q;
            int x = m * n + q;
            for (int i = 0; i < a.length; i++) {
                a[i] = x;
                x += q;
            }
            k -= sum;
            x = q * n + 1;
            for (int i = 0; i < a.length; i++) {
                if (k > x) {
                    a[i] += x;
                    k -= x;
                    x++;
                } else {
                    a[i] += k;
                    break;
                }
            }
        
        return a;
    }
```
