先看效果
![BF7D6374A9CBDD90740CA80F316AB739.jpg](https://pic.leetcode-cn.com/2f5ebdf8dc77624dd4e6321d57dbc1a3b585ffdbaef6b0ac73bbad6a38eb4546-BF7D6374A9CBDD90740CA80F316AB739.jpg)

我的思路是这样的
1.把所有的行和列,转换成0-99+的编号
2.然后从0开始搜索,找到有土地为1的加入hash表中
3.同时去找左跟上一块是否是土地,如果是,则装在同一个表中
4.同时拿个变量来装最大面积的索引值跟面积数量,得到最大面积的与他所在的位置
#这里我只写了最大的,如果有两块一样大的岛,再改改就ok啦

```
    // 30%机率岛面积
    function rand(){
        let n = Math.round(Math.random()*10);
        if(n>3){
            return 0;
        }else{
            return 1;
        }
    }

    //创建一个地图 w宽  h高
    function mainland(w=10,h=10) {
        let data = [];
        let j,x,i;
        for(j=0;j<h;j++){
            x = [];
            for (i=0;i<w;i++){
                x.push(rand());
            }
            data.push(x)
        }
        return data;
    }
    //随机色 用来标记岛 区分一下为了方便看
    function color16(){//十六进制颜色随机
        var r = Math.floor(Math.random()*200);
        var g = Math.floor(Math.random()*200);
        var b = Math.floor(Math.random()*200);
        var color = 'rgb('+r+','+g+','+b+')';
        return color;
    }
    
    //这里我是用vue写的,为了渲染视图哈哈
    var vue = new Vue({
        el:'#app',
        data:{
            list:[],
            box:{},
            hash:{},
            hash_max:{},
            rgb:[],
        },
        created:function () {
            this.list = mainland(10,10);

            let index = 1; //岛编号
            let hash = {}; //用来装岛
            let box = {}; //拿个盒子装起
            let rgb = {}; //颜色
            let hash_max = {i:0,n:0}; //用来装最大的岛

            let list = this.list;
            for(let i=0;i<list.length;i++){
                for (let j=0;j<list[i].length;j++){
                    let v = list[i][j]; //值
                    let n = (i*list[i].length)+j; //得到格子编号
                    box[n] = box[n] || {};
                    box[n].v = v;
                    box[n].index = 0;
                    if(v==1){ //如果有土地就装入盒子
                        let is = false;
                        let left=0,left_index;

                        let left_n = n-1; //左格编号
                        let top_n = n-list[i].length; //上格编号

                        if(j>0){//判断左格是否有土地,有则放在同一个盒子中

                            left = box[left_n].v; //左格值
                            left_index = box[left_n].index; //左格岛编号
                            if(left==1){
                                is = true;
                                box[n].index = left_index;
                                hash[left_index].push(n);

                                if(hash[left_index].length>hash_max.n){
                                    hash_max.n = hash[left_index].length;
                                    hash_max.i = left_index;
                                }
                            }
                        }

                        if(i>0){//判断上格是否有土地,有则放在同一个盒子中
                            let top =  box[top_n].v;
                            let top_index = box[top_n].index;
                            if(top==1){
                                //如果左格也是1则把跟左格同一个岛的移出来
                                //但是左格与上格编号是不一样的情况下
                                if(is && left_index!=top_index){
                                    for (let key in box){
                                        if(key!=n && box[key].index==left_index){
                                            box[key].index = top_index;
                                            hash[top_index].push(parseInt(key));

                                            if(hash[top_index].length>hash_max.n){
                                                hash_max.n = hash[top_index].length;
                                                hash_max.i = top_index;
                                            }
                                        }
                                    }
                                    hash[left_index] = []; //清空左岛
                                }


                                if(left_index!=top_index){
                                    box[n].index = top_index;
                                    hash[top_index].push(n);


                                    if(hash[top_index].length>hash_max.n){
                                        hash_max.n = hash[top_index].length;
                                        hash_max.i = top_index;
                                    }
                                }

                                is=true;
                            }
                        }
                        //如果左上格都不相连,则新建一个岛
                        if(!is){
                            rgb[index] = color16();
                            box[n].index = index;
                            hash[index] =  hash[index] || [];
                            hash[index].push(n);

                            if(hash[index].length>hash_max.n){
                                hash_max.n = hash[index].length;
                                hash_max.i = index;
                            }

                            index++; //新建一个岛
                        }

                    }
                }
            }
            this.hash = hash;
            this.box = box;
            this.rgb = rgb;
            this.hash_max = hash_max;
        }
    })

```



