跟一般的广度优先方法一样，记录的是n减掉之前走过的数字之后还需减掉的数额，按步数组织层数以表示和的个数
```
  int numSquares(int n) {
    if (n < 3) return n;
    vector<int> book;
    for (int i = 1;i <= int(sqrt(n));i++) book.push_back(i*i);
    queue<int> Q;
    Q.push(n);
    int step(0);
    while(Q.size()){
      int num = Q.size();
      int diff;
      step++;
      for(int i = 0;i<num;i++){
        int curr = Q.front();
        Q.pop();
        for (int i = 0;i < book.size() && book[i] <= curr;i++){
          diff = curr-book[i];
          if(diff == 0) return step;
          else Q.push(diff);
        }
      }
    }
    return -1;
  }
```
![image.png](https://pic.leetcode-cn.com/4f5621d0ea0a331eeeae7f000c155ef64db1b50432cf951b8f95bf8b2397cd6b-image.png)
DP方法
```
  int numSquares(int n) {
    vector<int> book(n+1,INT_MAX);
    book[0] = 0;
    for(int i = 0;i<=n;i++){
      for(int j = 1;(i+j*j)<=n;j++){
        book[i+j*j] = min(book[i+j*j],book[i]+1);
      }
    }
    return book.back();
  }
  int min(int x,int y){
    return x<y?x:y;
  }
```
![image.png](https://pic.leetcode-cn.com/8307528b3b3bdd222d79d623359fa786382be944d1f6ba3437a998417c66de50-image.png)