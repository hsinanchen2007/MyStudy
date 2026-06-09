与官方不同我使用一个二维数组int[26][2]来保存每个字符的最小和最大位置
按最小的排序然后遍历数组，更新最大值，但下一个字符的起始值大于当前的最大值的时候就找到了一组

算法不太好但是我感觉容易理解

```
    public List<Integer> partitionLabels(String S) {
      int[][] data=new int[26][2];
        char[] chars=S.toCharArray();
        ArrayList<Integer> res=new ArrayList<>();
        for (int i = 0; i < chars.length; i++) {
          int[] d=data[chars[i]-'a'];
          if (d[0]==0)
          {
              d[0]=i+1;
              d[1]=d[0];
          }
          else d[1]=i+1;
        }
        Arrays.sort(data,Comparator.comparingInt(a->a[0]));
        int start=1,end=data[0][1];
        for (int i = 1; i < data.length; i++) {
            if (data[i][0]==0)
                continue;
            if (data[i][0]>end&&end!=0){
                res.add(end-start+1);
                start=data[i][0];
                end=data[i][1];
                continue;
            }
            end=Math.max(end, data[i][1]);
            
        }
        res.add(end-start+1);
        return res;
    }
```
