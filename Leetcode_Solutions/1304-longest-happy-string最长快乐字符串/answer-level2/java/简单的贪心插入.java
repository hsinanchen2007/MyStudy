 每次从数量最多的字符中取一个插入当前序列，注意：同一种字符不能连续取用超过2次
```java
    public String longestDiverseString(int a, int b, int c) {
        int[][] arr={{a,'a'},{b,'b'},{c,'c'}};
        StringBuilder sb=new StringBuilder();
        int i=0;
        while (i<a+b+c) {
            Arrays.sort(arr, Comparator.comparingInt(x -> x[0]));
            //判断当前取的字符有没有超过3次，有就使用倒数第二个
            if(i>1&&sb.charAt(i-1)==sb.charAt(i-2)&&sb.charAt(i-1)==arr[2][1]){
                if(arr[1][0]==0) break;
                sb.append((char)arr[1][1]);
                arr[1][0]--;
            }else {
                if(arr[2][0]==0) break;
                sb.append((char)arr[2][1]);
                arr[2][0]--;
            }
            i++;
        }
        return sb.toString();
    }
```
