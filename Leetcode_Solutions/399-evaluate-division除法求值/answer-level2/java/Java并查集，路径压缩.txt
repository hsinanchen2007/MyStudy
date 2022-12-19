首先来一版不带路径压缩的

```java
private HashMap<String,String> parent=new HashMap<>();

private HashMap<String,Double> quotient=new HashMap<>();

//不带路径压缩
public String find(String p){
    while (parent.get(p)!=p) {
        p=parent.get(p);
    }
    return p;
}

public void init(String s){
    if (!parent.containsKey(s)) {
        parent.put(s,s);
        quotient.put(s,1.0);   
    }
}

public void merge(String a,String b,Double value){
    init(a);init(b);
    String fa=find(a); // a/fa=val[a], b/fb=val[b]
    String fb=find(b);
    if (fa.equals(fb)) {
        return;
    }
    parent.put(fa,fb);
    quotient.put(fa,value*(cal(b)/cal(a))); //cal(a)和cal(b)代表a和b到根节点的总值
}

public double[] calcEquation(List<List<String>> equations, double[] values, List<List<String>> queries) {
    for (int i=0;i<equations.size();i++) {
        List<String> equation=equations.get(i);
        merge(equation.get(0),equation.get(1),values[i]);
    }
    double[] res=new double[queries.size()];
    int index=0;
    for (List<String> query:queries) {
        String a=find(query.get(0));
        String b=find(query.get(1));
        System.out.println(a+" "+b);
        if (!parent.containsKey(query.get(0)) || !parent.containsKey(query.get(1)) || !a.equals(b)) {
            res[index++]=-1;
        }else{
            //没有路劲压缩,需要遍历整个路劲求积
            res[index++]=cal(query.get(0))/cal(query.get(1));
        }
    }
    return res;
}


//计算当前节点到根节点的路径乘积
public double cal(String index){
    double res=quotient.get(index);
    while(parent.get(index)!=index){
        index=parent.get(index);
        res*=quotient.get(index);
    }
    return res;
}
```

其实这题我开始想到就是建图然后BFS，并查集我是真没想到，看来还是不够敏锐，不过有一说一并查集的方法确实比较麻烦。

这里我的并查集的方向是

```java
a/b=2 , b/c=3
    
        c  1
        ^
        |
        b  3
        ^
        |
        a  2
```

`val`代表的是**当前节点**是**直接父节点**的多少倍，也就是 `A/fatherA`  ，重点就是合并两个集合的时候需要注意：

```java
已知
a / fa = val[a]
b / fb = val[b]
现在我们要合并a，b且 a / b=value
所以我们需要设置 parent[fa]=fb
由于fa父节点发生了变化所以它的值也需要变化,也就是要求 fa/fb的值
val[fa] = fa/fb = a/b * b/fb * fa/a = value * (val[b] / val[a])
```

**解法二**

```java
private HashMap<String,String> parent=new HashMap<>();

private HashMap<String,Double> quotient=new HashMap<>();

//带路径压缩的
public String find(String p){
    if (parent.get(p)!=p) {
        //需要先保存父亲的值,因为后面压缩后树只有两层,后面*的就是根节点的权值1,是不对的
        //这里可以看看上面的并茶几的方向和值来判断
        String f=parent.get(p); 
        parent.put(p,find(f));
        //这样压缩后的子节点才是正确的
        quotient.put(p,quotient.get(p)*quotient.get(f));
    }
    return parent.get(p);
}

public void init(String s){
    if (!parent.containsKey(s)) {
        parent.put(s,s);
        quotient.put(s,1.0);   
    }
}

public void merge(String a,String b,Double value){
    init(a);init(b);
    String fa=find(a); // a/fa=val[a], b/fb=val[b]
    String fb=find(b);
    if (fa.equals(fb)) {
        return;
    }
    parent.put(fa,fb);
    quotient.put(fa,value*(quotient.get(b)/quotient.get(a))); 
}

public double[] calcEquation(List<List<String>> equations, double[] values, List<List<String>> queries) {
    for (int i=0;i<equations.size();i++) {
        List<String> equation=equations.get(i);
        merge(equation.get(0),equation.get(1),values[i]);
    }
    double[] res=new double[queries.size()];
    int index=0;
    for (List<String> query:queries) {
        String a=query.get(0);
        String b=query.get(1);
        if (!parent.containsKey(a) || !parent.containsKey(b)) {
            res[index++]=-1;
        }else{
            //先做路径压缩
            res[index++]=find(a).equals(find(b))?quotient.get(a)/quotient.get(b):-1;
        }
    }
    return res;
}
```

这里可以看到已经省略了`cal` 函数计算从当前节点到根节点的总权值积，因为这里路径压缩已经将树压缩到只有两层了，所以并不需要了，既然要压缩到只有两层，这里就只能使用递归来压缩，循环的版本没办法压到只有两层，这里需要注意压缩中值的变化。

**解法三**

图的解法放到了 [栈和队列专题](http://imlgw.top/2019/10/01/leetcode-zhan-dui-lie/) 中了