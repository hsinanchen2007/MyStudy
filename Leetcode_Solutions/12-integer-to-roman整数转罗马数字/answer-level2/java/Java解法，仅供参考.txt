```
class Solution {
    enum IntLinkRoman{
        I(1), IV(4), V(5), IX(9), X(10), XL(40), L(50), XC(90), C(100), CD(400), D(500), CM(900), M(1000);
        private int intNum;

        IntLinkRoman(int intNum) {
            this.intNum = intNum;
        }

        public int getIntNum() {
            return intNum;
        }

        public void setIntNum(int intNum) {
            this.intNum = intNum;
        }
    }

    public String intToRoman(int num){
        StringBuilder stringBuilder = new StringBuilder();
        List<IntLinkRoman> list = Arrays.asList(IntLinkRoman.values());
        int temp = num;
        for (int i=list.size() - 1; i >= 0 ; i--){
            IntLinkRoman intLinkRoman = list.get(i);
            int a = temp / intLinkRoman.getIntNum();
            if (a != 0){
                for (int j=0; j<a; j++){
                    stringBuilder.append(intLinkRoman.name());
                }
            }
            temp = temp % intLinkRoman.getIntNum();
            if (temp == 0){
                break;
            }
        }
        return stringBuilder.toString();
    }
}
```
![Snipaste_2019-07-17_15-38-46.png](https://pic.leetcode-cn.com/b9d7eb218e30ed374bbc21d4846f5a344ce3f0af141620a538b3c1862bd6f1cb-Snipaste_2019-07-17_15-38-46.png)
![Snipaste_2019-07-17_15-38-28.png](https://pic.leetcode-cn.com/dcc1b7ba7e2bde82bf8796e74dc9c57de1009db94dbc58eef74a8247e4b3a333-Snipaste_2019-07-17_15-38-28.png)

思想：枚举出特征值，然后将入参除以特征值（从大到小），结果a的个数就是对应罗马数字的个数

