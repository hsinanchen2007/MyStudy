class Solution {
    public int minDistance(String word1, String word2) {
        int m = word1.length() + 1;   // 加1是给出空出的第一个位置 #号位置
        int[] arr = new int[m];

        for (int i = 0; i < m; i++) {
            arr[i] = i;
        }

        int temp1 = 0;
        int temp2 = 0;
        for (int i = 0; i < word2.length(); i++) {
            for (int j = 0; j < m; j++) {
                if (j == 0) {
                    temp1 = arr[0];  // 存储i-1，j-1的值
                    arr[0] += 1;
                } else {
                    temp2 = arr[j];  // 存储当前值
                    if (word1.charAt(j-1) == (word2.charAt(i))){ arr[j] = temp1; }
                    else {
                        if(temp1<=temp2&&temp1<=arr[j-1]) arr[j] = temp1+1;
                        else if(temp2<=temp1&&temp2<=arr[j-1]) arr[j] = temp2+1;
                        else arr[j] = arr[j-1]+1;
                    }
                    temp1 = temp2;
                }
            }

        }
        return arr[m-1];
    }
}