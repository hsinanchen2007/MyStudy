```
class Solution {
    public String intToRoman(int num) {
        
        int[] divs ={1,4,5,9,10,40,50,90,100,400,500,900,1000};
        String[] roman ={"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
        
        int div = 0;
        int temp = 0;
        StringBuilder sb = new StringBuilder();
        
        for(int i = 12; i >= 0 && num != 0;i--){
            div = divs[i];
            temp = num/div;
            while(temp != 0){
                sb.append(roman[i]);
                temp--;
            }
            num=num % div;
        }
        return sb.toString();
    }
}
```

![{47357CEB-0A83-4CA0-BDD2-797E89BD35FC}.png.jpg](https://pic.leetcode-cn.com/7e5d0e2c98e9ead94fcda64f1923a43e2c770cb1d7a12813778fa91409eec234-%7B47357CEB-0A83-4CA0-BDD2-797E89BD35FC%7D.png.jpg)
