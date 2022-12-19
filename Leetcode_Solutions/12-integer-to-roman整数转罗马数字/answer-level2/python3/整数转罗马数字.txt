```
class Solution:
    def intToRoman(self, num: int) -> str:
        num1 = num % 1000
        count1 = int(num / 1000)
        num2 = num1 % 100
        count2 = int(num1 / 100)
        num3 = num2 % 10
        count3 = int(num2 / 10)
        list1 = ['M','MM','MMM']
        list2 = ['C','CC','CCC','CD','D','DC','DCC','DCCC','CM']
        list3 = ['X','XX','XXX','XL','L','LX','LXX','LXXX','XC']
        list4 = ['I','II','III','IV','V','VI','VII','VIII','IX']
        str = ""
        if count1 != 0:
            str = str + list1[count1 - 1]
        if count2 != 0:
            str = str + list2[count2 - 1]
        if count3 != 0:
            str = str + list3[count3 - 1]
        if num3 != 0:
            str = str + list4[num3 -1]
        return(str)
```
