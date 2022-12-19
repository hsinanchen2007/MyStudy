返回值要求是二维数组形式，而连续正数序列长度不一，怎样处理？
**处理方法**
（1）list中类型设置为数组类型，List<int[]> res = new ArrayList<>();
（2）返回时list转为数组，res.toArray(new int[0][]);

**暴力法**
枚举每一种不同序列的具体取值，若刚好分配完时，则添加到结果集中
```java 
public int[][] findContinuousSequence(int target) {
    List<int[]> res = new ArrayList<>();

    if (target<=2){
        return null;
    }

    for (int i = 1;i<target/2+1;i++){
        int temp = target;
        int count = i;
        while (temp>0){
            temp = temp - count;   //这里count是指具体取值时的可能性
            count++;
        }

        if (temp==0){          //若temp刚好等于零，则说明可按这个来取值
            int[] arr = new int[count-i];
            int a = i;
            for (int j = 0;j<arr.length;j++){
                arr[j] = a;
                a++;
            }
            res.add(arr);
        }
    }

    return res.toArray(new int[0][]);
}
```

**双指针法**
(1)之和小于target时，max继续挪，并累加到sum中
(2)之和大于target,将min从sum剔除，min向后挪
(3)之和等于target，数组长度为max-min+1,赋值并将数组添加到结果集中

```java
public int[][] findContinuousSequence1(int target){
    List<int[]> res = new ArrayList<>();

    if (target<=2){
        return null;
    }

    int min = 1;
    int max = 2;
    int sum = min+max;

    while (min<max&&max<target){
        if (sum<target){
            max++;
            sum+=max;
        }else if (sum>target){   //sum大于目标值
            sum-=min;
            min++;
        }else {            //sum等于目标值的情形
            int[] arr = new int[max-min+1];
            int a = min;
            for (int j = 0;j<arr.length;j++){
                arr[j] = a;
                a++;
            }
            res.add(arr);

            sum-=min;
            min++;
        }
    }

    return res.toArray(new int[0][]);
}
```



