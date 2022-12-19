    已知斐波那契数列的计算公式 f[i + 2] = f[i + 1] + f[i] = f[i + 1] + (f[i - 1] + f[i - 2]);

    那么我们在递归运算时可以这样传递参数：
    上一个数字last(即f[i+1])，上一个数字和它的上一个数字的和target(即f[i + 1] + f[i])。
    我们的目标就是要找到一个值为target的数，
    然后求出下一个target(即last + val，val为当前结点的值)，如此进行递归。
    在深度遍历过程中记得剪枝，否则解空间会很大。
```
class Solution {
    public String numStr;
    public List<Integer> list;
    public List<Integer> splitIntoFibonacci(String num) {
        list = new ArrayList<>();
        if(num.length() < 3) return list;
        numStr = num;
        String first, second;
        for(int i = 1; i <= num.length() / 2; i ++){
            if(i > 1 && num.charAt(0) == '0') return list;
            first = num.substring(0, i);
            int f = Integer.valueOf(first);

            list.add(f);
            for(int j = i + 1; j <= num.length() - Math.max(i, j - i); j ++){
                if(j - i > 1 && num.charAt(i) == '0') break;
                second = num.substring(i, j);
                int s = Integer.valueOf(second);
                list.add(s);
                if(traceBack(num.length() - j, j, f + s, s))
                    return list;
                list.remove(1);
                
                //防止下次的值大于表示范围
                if(s > (Integer.MAX_VALUE - 8) / 10) break;
            }
            list.remove(0);

            //防止下次的值大于表示范围
            if((Integer.MAX_VALUE - 8) / 10 < f) return list;
        }
        return list;
    }

    public boolean traceBack(int left, int start, int target, int last){
        if(left <= 0) {
            return true;
        }
        for(int i = 1; i <= left; i ++){
            if(i > 1 && numStr.charAt(start) == '0') break;
            String num = numStr.substring(start, start + i);
            int val = Integer.valueOf(num);

            //如果当前结点的值大于目标，则可以退出该结点
            if(val > target) return false;
            if(val == target){
                list.add(val);
                System.out.println(val);
                if(traceBack(left - i, start + i, last + val, val))
                    return true;
                list.remove(list.size() - 1);
            }
            //避免下次的值超出表示范围
            if((Integer.MAX_VALUE - 8) / 10 < val) return false;
        }
        return false;
    }
}
```

