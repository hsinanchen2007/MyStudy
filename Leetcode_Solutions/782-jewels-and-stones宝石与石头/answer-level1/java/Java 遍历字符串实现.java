```java
    public int numJewelsInStones(String J, String S) {
        int num = 0;
        for (int i = 0; i < S.length(); i++) {
            String temp = S.substring(i, i + 1);
            if (J.indexOf(temp) != -1) {
                //b包含
                num++;
            }
        }
        return num;
    }
```