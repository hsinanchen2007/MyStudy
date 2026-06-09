RT
```
class Solution {
    public String intToRoman(int num) {
        String ans = "";
        String[] sym = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
        int[] symInt = {1,4,5,9,10,40,50,90,100,400,500,900,1000};
        int temp = num;
        int i = 12;
        while(temp > 0&&i >= 0)
        {
            if(temp - symInt[i]>=0)
            {
                ans = ans + sym[i];
                temp = temp - symInt[i];
                continue;
            }
            if(temp - symInt[i] < 0)
            {
                i--;
            }
        }
        return ans;
    }
}
```
