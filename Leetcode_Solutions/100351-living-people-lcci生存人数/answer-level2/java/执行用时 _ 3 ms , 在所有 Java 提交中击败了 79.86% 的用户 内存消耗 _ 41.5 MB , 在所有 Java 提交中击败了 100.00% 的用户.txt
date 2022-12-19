### 解题思路

1909年死的人应该在1909年还算存活，1910年不算了，，没理解好，所以应该是102大小的数组。
### 代码

```java
class Solution {
    public int maxAliveYear(int[] birth, int[] death) {
        int [] alives = new int[102];
        for(int i=0;i<birth.length;i++){
            int birthYear = birth[i];
            int deathYear = death[i];
            alives[birthYear-1900] = alives[birthYear-1900]+1;
            alives[deathYear-1899] = alives[deathYear-1899]-1;
        }
        int maxyear = 0;
        for(int i=1;i<alives.length;i++){
            alives[i]=alives[i]+alives[i-1];
        }

        for(int i=0;i<alives.length-1;i++){
            if(alives[i]>alives[maxyear]){
                maxyear = i;
            }
        }

        return maxyear+1900;
    }
}
```