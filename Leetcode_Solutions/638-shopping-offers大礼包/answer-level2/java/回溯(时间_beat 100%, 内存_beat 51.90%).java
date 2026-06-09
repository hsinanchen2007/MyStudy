![微信图片_20191110142256.png](https://pic.leetcode-cn.com/ad16dc04b059f6f43af14ecdb6cd4814a947c2e893b096e90e2c4e625ffa4e2f-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20191110142256.png)


**本人不喜欢函数的参数列表过长，看的眼花，故弄了几个全局变量，不喜勿喷。**


# 代码
```java [-无注释]
class Solution {
    private List<Integer> global_needs, global_price;
    private List<List<Integer>> global_special;
    private int sum = 0, res = Integer.MAX_VALUE;

    public int shoppingOffers(List<Integer> price, List<List<Integer>> special, List<Integer> needs) {
        global_needs = needs;
        global_special = special;
        global_price = price;
        find(0);
        return res;
    }

    private void find(int begin) {
        int temp_sum = sum;
        for (int i = 0; i < global_needs.size(); ++i)
            sum += global_needs.get(i) * global_price.get(i);
        res = Math.min(res, sum);
        sum = temp_sum;
        for (int i = begin; i < global_special.size(); ++i) {
            List<Integer> cur_special = global_special.get(i);
            int special_num = cal_special_num(cur_special);
            if (special_num != 0) {
                for (int j = 1; j <= special_num; ++j) {
                    List<Integer> temp_needs = new ArrayList<>(global_needs);
                    for (int k = 0; k < global_needs.size(); ++k)
                        global_needs.set(k, global_needs.get(k) - cur_special.get(k) * j);

                    sum += cur_special.get(global_needs.size()) * j;
                    find(i + 1);
                    global_needs = temp_needs;
                    sum = temp_sum;
                }
            }
        }
    }

    private int cal_special_num(List<Integer> item) {
        int max = Integer.MAX_VALUE;
        for (int i = 0; i < global_needs.size(); ++i) {
            int cur_need = global_needs.get(i), cur_item = item.get(i);
            if (cur_need < cur_item)
                return 0;

            if (cur_item != 0)
                max = Math.min(cur_need / cur_item, max);
        }
        return max;
    }
}
```
```java [-有注释]
class Solution {
    private List<Integer> global_needs, global_price;
    private List<List<Integer>> global_special;
    private int sum = 0, res = Integer.MAX_VALUE;

    public int shoppingOffers(List<Integer> price, List<List<Integer>> special, List<Integer> needs) {
        //给全局变量赋值(引用传递)
        global_needs = needs;
        global_special = special;
        global_price = price;
        find(0);
        return res;
    }

    private void find(int begin) {
        //备份sum值
        int temp_sum = sum;
        // 把global_needs中的物品依次用 单价购买 的形式 补齐
        for (int i = 0; i < global_needs.size(); ++i)
            sum += global_needs.get(i) * global_price.get(i);
        //res取最小值
        res = Math.min(res, sum);
        //从备份中恢复sum值
        sum = temp_sum;
        //以入参begin为起点，遍历global_special
        for (int i = begin; i < global_special.size(); ++i) {
            //给当前大礼包 取的变量名，不然看的费劲
            List<Integer> cur_special = global_special.get(i);
            //global_needs中的物品 最多需要几个当前的大礼包
            int special_num = cal_special_num(cur_special);
            //所需要的大礼包 数量不为0时
            if (special_num != 0) {
                //根据 当前大礼包所需的数量，for循环 + 递归调用
                for (int j = 1; j <= special_num; ++j) {
                    //备份当前global_needs
                    List<Integer> temp_needs = new ArrayList<>(global_needs);
                    //修改global_needs的所需物品个数
                    for (int k = 0; k < global_needs.size(); ++k)
                        global_needs.set(k, global_needs.get(k) - cur_special.get(k) * j);
                    //算账(+ 大礼包单价 × 大礼包数量)
                    sum += cur_special.get(global_needs.size()) * j;
                    //递归调用
                    find(i + 1);
                    //从备份中恢复global_needs
                    global_needs = temp_needs;
                    //从备份中恢复sum
                    sum = temp_sum;
                }
            }
        }
    }

    //入参item：指大礼包
    //计算global_needs中的物品，最多需要几个 当前大礼包
    private int cal_special_num(List<Integer> item) {
        //max初始化为 Integer的最大值
        int max = Integer.MAX_VALUE;
        for (int i = 0; i < global_needs.size(); ++i) {
            //global_needs中 当前下标的所需物品个数 < 大礼包中当前下标的物品个数，直接return 0
            //不能超出待购清单的物品个数
            if (global_needs.get(i) < item.get(i))
                return 0;
            //防止除数为0，抛出异常
            if (item.get(i) != 0)
                max = Math.min(global_needs.get(i) / item.get(i), max);
        }
        return max;
    }
}
```
