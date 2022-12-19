# java 2ms
#### 优化思路：
`i`和`j` 取范围值（0到最接近bound的x或者y的幂次数）
#### 考虑边界值：
```ini
x == 1 与 y == 1时候的幂次无限循环自身，需要提前排除掉
```
>>剩下的就是常规做法，每取一个x，遍历一圈y的幂次极限，与bound判断大小差异，以及是否已经出现过（用set的contains方法排除）我的代码相当臃肿，但是个人觉得是符合做题时候的思路，一步步深化出现的

```reasonml
public class solution{
    public List<Integer> powerfulIntegers(int x, int y, int bound) {
        //保存结果（优化的话，可以省去这个，直接使用set作结果集，我这边是为了方便理解）
        List<Integer> res = new ArrayList<>();
        //判断值是否出现过了，去重
        Set<Integer> hs = new HashSet<>();
        int x_temp = bound;
        int y_temp = bound;
        //x取多少次幂极限逼近bound
        int x_max = 0;
        //y同上
        int y_max = 0;

        //边界值 去掉
        if (x == 1 && y == 1) {
            if (bound >= 2) res.add(2);
            return res;
        } else if (x == 1) {
            //记录y的幂次
            int j = 0;
            int sum = (int) (1 + Math.pow(y, j));
            while (sum <= bound) {
                res.add(sum);
                //每次取完值将幂次扩大
                j ++;
                sum = (int) (1 + Math.pow(y, j));
            }
            return res;
        } else if (y == 1) {
            //同上，只是y换x
            int i = 0;
            int sum = (int) (1 + Math.pow(x, i));
            while (sum <= bound) {
                res.add(sum);
                i ++;
                sum = (int) (1 + Math.pow(x, i));
            }
            return res;
        }

        //这一步，是为了求出当x非1情况下，它所能逼近bound的最大幂次
        while (x_temp != 0 && x != 1) {
            x_max ++;
            x_temp = x_temp / x;
        }
        //同上，求y的最大幂次
        while (y_temp != 0 && y != 1) {
            y_max ++;
            y_temp = y_temp / y;
        }

        //常规做法，挨个遍历，范围已经被缩小，不会TLE
        for (int i = 0; i <= x_max; i ++) {
            for (int j = 0; j <= y_max; j ++) {
                int sum = (int) (Math.pow(x, i) + Math.pow(y, j));
                if (sum > bound) {
                    break;
                }
                if (!hs.contains(sum)) {
                    hs.add(sum);
                    res.add(sum);
                }
            }
        }
        return res;
    }
}

```