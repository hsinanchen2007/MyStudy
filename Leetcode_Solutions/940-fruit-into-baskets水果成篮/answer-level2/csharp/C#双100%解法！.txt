```
public class Solution {
    public int TotalFruit(int[] tree) {
        int position=0;
        int a=tree[0];
        int b=-1;
        int i=0;
        int j=0;
        int now=0;//现在果篮里的果子数量
        int answer=0;//之前果篮里果子的最大数量记录！
        while(true){
            for(i=position;i<tree.Length;i++){
                if(tree[i]!=a){//遇到第二种果子了！
                    b=tree[i];
                    break;
                }
            }
            if(b==-1){//如果b依旧是-1，就说明我已经遍历完了所有可能了！所以就可以直接输出答案啦！
                if(position==0){return tree.Length;}//如果position依旧是0，就说明果树种类少于2，所以直接return果树数量就可以了。
                return answer;
                }
            //开始从position位置往后检索！（也就是我们开始采集果子啦！）
            for(j=position;j<tree.Length;j++){
                if(tree[j]!=a&&tree[j]!=b){break;}//如果这棵树的果子不是a或者b，就没法继续采集了哦！
            now++;//增加现在果篮里的果子数量！
            }
            if(now>answer){answer=now;}//如果最大纪录比我们现在果篮里的果子少的话，就得更新记录啦！
            if(position==0&&j==tree.Length){return tree.Length;}
            a=b;
            b=-1;
            position=i;
            now=0;
        }
        return 24601;
    }
}
```
//我做了整整一个小时...这正常吗;w;