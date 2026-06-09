候选人法，拆分for遍历：
1.清楚一件事，每个人必然认识自己。数组的对角线一定是1。
2.在第一次for循环中，对角线左下区为盲区，右上区为考虑区域。选出名人候选人。
3.正是因为存在左下的盲区，才需要进行第二次for循环检验。
![c57b5b10374bf6c7bbb89a86219b3d8.jpg](https://pic.leetcode-cn.com/680d267d1f2fe5a3b7f28977dd1ac99fa26a21b76bd369a949c71bf7359e37fa-c57b5b10374bf6c7bbb89a86219b3d8.jpg)


注：可不可能存在多名候选人？不可能。为什么？请看程序中here处注释。

```c

bool knows(int a, int b);
int findCelebrity(int n){
    int i=0,j;
	for(j=0;j<n;j++){
        if(knows(i,j)){  //此时i必不可能是名人了，j有可能。
            i=j;   
//here：做完此步，来到了数组对角线的某点（i，j）处
//或者可以说，来到了（i，i）处。继续往右侧遍历。如果能够遍历完此行
//说明i并不认识大于i编号的人，也就代表任何大于i编号的人不配做名人。
//这就说明比一旦候选人i出现，大于编号i其他任何人都不可能有机会了。
        }
	}
    for(j=0;j<n;j++){
        if(j==i) continue;
        if(knows(i,j)) return -1;
        if(!knows(j,i)) return -1;
    }
	return i;
}

```


常规做法，嵌套for遍历：
对每个号码为i的人，判断他是否认识所有人？所有人是否认识他？
```c
bool knows(int a, int b);
int findCelebrity(int n){
	for(int i=0;i<n;i++){
		for(int j=0;i<n;j++){
			if(j!=i && knows(i,j) || !knows(j,i)){
				break;	
			}
			if(j==n-1){
				return i;
			}
		}
	}
	return -1;
}
```

