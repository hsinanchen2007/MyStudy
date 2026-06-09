由于得到最大值点是起跳点，一定不是由别的点跳跃来的，所以每当我们跳跃得到一个点时就将它添加到
一个非起始点的目录下，遍历的时候就可以略去它，用HashSet记录这些非起始点。这对于节点特别多的
情况，可以减少很多遍历。
每求得一次一个点的跳跃最大次数，我们可以记录下它以便以后调用。我使用的是HashMap，但是看了别
的题解发现使用一个dp数组更加方便（其实思路是一样的）。^^ 
对于每一个点的最大跳跃次数的计算，我们从它依次向左1，左2....一直到左d或0循环计算。若遇到相等
或更高的柱子，就跳出循环。同理对右边。

class Solution {
    HashSet<Integer> hs = new HashSet();
    HashMap<Integer,Integer> hm = new HashMap<Integer,Integer>();
    int maxjump=1;

    public int maxJumps(int[] arr, int d) {
        
        for(int i=0;i<arr.length;i++){
            if(hs.contains(i))  continue; //既然这个点是由别的点跳跃得到的（算不了最大值）那就跳过它吧！

            maxjump=Math.max(maxjump,time(arr,d,i));
        }

        return maxjump;
        
    }

    //计算一个点的最大跳跃次数
    public int time(int[] arr,int d,int k){
        int maxtime=1;
        
        if(k>0){   //对于最左边就不向左跳跃了
            for(int i=k-1;i>=Math.max(0,k-d);i--){
                if(arr[k]<=arr[i])
                    break;

                hs.add(i);    //被跳跃得到的点不是最大起跳点，记录下来，之后就不用遍历了。

                if(hm.containsKey(i))  //如果计算过，hashmap里就有这个key呀！
                    maxtime=Math.max(maxtime,hm.get(i)+1);
                else
                    maxtime=Math.max(maxtime,time(arr,d,i)+1);
            }
        
        }
        
        if(k<arr.length-1){    //对于最右边就不向右跳跃了
            for(int i=k+1;i<=Math.min(arr.length-1,k+d);i++){                
                if(arr[k]<=arr[i])
                    break;
                
                hs.add(i);       //被跳跃得到的点不是最大起跳点，记录下来，之后就不用遍历了。

                if(hm.containsKey(i))    //如果计算过，hashmap里就有这个key呀！
                    maxtime=Math.max(maxtime,hm.get(i)+1);
                else
                    maxtime=Math.max(maxtime,time(arr,d,i)+1);
            }
        }
        
        hm.put(k,maxtime);  // 计算过的数值要保存下来，以便以后计算方便。
        return maxtime;
    }
}