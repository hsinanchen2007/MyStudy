```
public static int[] deckRevealedIncreasing(int[] deck){
        int[] res = new int[deck.length];
//       用-1标记未确定的数；
        for (int i = 0; i <res.length ; i++) {
            res[i] = -1;
        }
//      将deck 排好序
        qsort(deck,0,deck.length-1);
        int comp=0;//已经放置的数量；
        boolean flag = true;//元素确定标记；
        int i =0;//res遍历指针
        int j =0;//deck遍历指针
        while(comp<res.length){
//      当放完一趟后将i复位
            if(i==res.length)
                i = 0;
            if(res[i]==-1&&flag==true){//当前位置未放数 且可以放数
                res[i] = deck[j++];
                comp++;
                flag = false;

            }
            if(res[i]==-1&&flag==false)//当前位置未放数 但不能放数时将flag复位
                flag = true;
            i++;
        }
        return res;
    }
//    快排
    public static void qsort(int[] a, int left,int right){
        int q;
        if(left<right) {
            q = partion(a, left, right);
            qsort(a,left,q-1);
            qsort(a,q+1,right);
        }
    }
    public static int partion(int[] a,int left ,int right){
        int key = a[right];
        int i = left;
        int j = right;
        while(true){
            while(i<j&&a[i]<=key) i++;
            while(i<j&&a[j]>=key) j--;
            if(i>=j)
                break;
            int tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
        }
        a[right] = a[i];
        a[i] = key;
        return i;

    }

```
