![image.png](https://pic.leetcode-cn.com/43f8a8c80c0abe5d8c9657300a9701d903dec412eda61566ea1b2b1641f5752e-image.png)
```
/**
     * 比较难确定的是最后一个0复制的次数。采用flag进行标记，如果是只复制了一次就满了，则flag=1；如果是复制了两次，则flag=0
     * @param arr
     */
public  void duplicateZeros(int[] arr) {
            int cnt=0;
            int i=0;//找到最终返回数组的最后一个数字所在索引
            int flag=0;
            for (; i <arr.length ; i++) {
                cnt++;
                if (cnt==arr.length){
                    flag=1;//从这里跳出去的,说明最后一个0只复制了一次
                    break;}
                if (arr[i]==0)//如果该位是0，则多计一次
                    cnt++;
                if (cnt>=arr.length) {
                    break;
                }
            }
            int j=i;
            int k;
            if (flag==1){//最后一个0应该只出现一次
                arr[arr.length-1] = arr[j];
                k=arr.length-2;
            } else {
                arr[arr.length-1] = 0;
                arr[arr.length-2] = 0;
                k=arr.length-3;
            }
            for ( j = i-1; j >=0 ; j--) {
                if (k>=0)
                    arr[k--] = arr[j];
                if (arr[j]==0){
                    if (k>=0) arr[k--] = 0;
                }
            }
        }
```
