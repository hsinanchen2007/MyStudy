执行结果：通过
执行用时 :2 ms, 在所有 java 提交中击败了100.00%的用户
内存消耗 :36.2 MB, 在所有 java 提交中击败了100.00%的用户

此题就是对应二元一次方程组进行求解，设巨无霸汉堡个数为x，小黄堡为y，则4x + 2y = tomatoSlices，换个写法为
2(2x + y) = tomatoSlices，所以tomatoSlices必为双数，先对输入进行判断，如果tomatoSlices为单数，是不可能
有满足题意的解的，附代码如下：
public List<Integer> numOfBurgers(int tomatoSlices, int cheeseSlices) {

        List<Integer> list = new ArrayList<>();
        if(tomatoSlices % 2 == 0)
        {
            int x = 2 * cheeseSlices - tomatoSlices / 2;
            int y = tomatoSlices / 2 - cheeseSlices;
            if (x % 1 == 0 && x >= 0 && y % 1 == 0 && y >= 0)
            {
                list.add(y);
                list.add(x);
            }
        }
        return list;

    }

