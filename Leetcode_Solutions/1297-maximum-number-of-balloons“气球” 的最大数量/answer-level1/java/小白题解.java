### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int maxNumberOfBalloons(String text) {
    int[] balon=new int[5];
    if(1<=text.length()&&text.length()<=10000)
    { for(int i=0;i<text.length();i++)
      { char f=text.charAt(i);
        if(f=='a')
        {
            balon[0]++;
        }
        if(f=='b')
        {
            balon[1]++;
        }
        if(f=='l')
        {
           balon[2]++;
        }
        if(f=='n')
        {
            balon[3]++;
        }
        if(f=='o')
        {
            balon[4]++;
        }
       
      }
      balon[2]=balon[2]/2;
      balon[4]=balon[4]/2;
     Arrays.sort(balon);
     //return balon[0];
    }
    else{
        System.out.println("字符串太长");
    }
    return balon[0];
    }   
}

