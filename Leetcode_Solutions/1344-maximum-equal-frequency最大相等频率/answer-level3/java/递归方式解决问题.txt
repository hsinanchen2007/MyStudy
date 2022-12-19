public class Subject006 {

    public static void main(String[] args) {
        Subject006 test = new Subject006();

        int num[] = {10,2,8,9,3,8,1,5,2,3};
        System.out.println(test.maxEqualFreq(num)+ " 期望值：8");
        System.out.println("-------------------------------------");
        int num1[] = {1,1,1,2,2,2,3,3,3,4,4,4,5};
        System.out.println(test.maxEqualFreq(num1)+ " 期望值：13");
        System.out.println("-------------------------------------");
        int num2[] ={2,2,1,1,5,3,3,5};
        System.out.println(test.maxEqualFreq(num2)+ " 期望值：7");
        System.out.println("-------------------------------------");
        int num3[] ={1,1,1,2,2,2};
        System.out.println(test.maxEqualFreq(num3) + " 期望值：5"  );
        System.out.println("-------------------------------------");

    }

    /**

     *
     * @param num
     * @return
     */
    /**
     *  思路分析：
     *  满足条件的数组
     *      1、全是都同一个数字的数组   最大频率和最小频率一致且频率只有一种         [1，1，1，1]
     *      2、全是不同数字            最大频率和最小频率一致且都是1               [1,2,3,4]
     *      3、存在俩个不同频率        最小频率为1（）                            [1,1,1,2,2,2,3]
     *      4、存在俩个不同频率        最大频率比最小频率大1且最大/最小频率频率只有一个元素   [1,1,1,2,2,3,3]  [1,1,2,2,3,3,2,1]
     *
     *  递归思想：题意中给出数组范围 2~10^5 所以不存在空数组，可以不进行判断
     *      只要满足上面4给场景之1则都可以组成符合题意的数组，因此跳出条件就是满足上面4中之一。
     *      尽量将上面条件进行逻辑合并
     *      1和2合并为最大频率和最小频率一致（频率只有一个,且都是相同元素或则都是不同元素）
     *      3和4 合并为  存在不同的俩个频率 && （ 最小频率为1且只有一个元素 || 最大频率比最小频率大1且最大只有一个元素 ）
     *
     *      构建变量
     *          frequencyNum  频率数量
     *          maxfrequency  最大频率
     *          minfrequency  最小频率
     *          mapFequency   频率map 泛型为   Integer，Set   分别对应的是 频率和元素
     *                 maxFence  set 元素
     *                 minFence  set 元素
     *
     * @param num
     * @return
     */
    public int  maxEqualFreq(int num[]) {


        // 最大次数 最小次数  最大次数元素数   最小次数元素数
        int maxfrequency = 0;
        int minfrequency = 0;
        int frequencyNum = 0;
        Map<String,Set> mapFequency = new HashMap<>();



        for(int i=0; i < num.length; i++){
            // 记录出现次数
            int fens = 0;
            for(int j=0; j < num.length; j++){
                if(num[i] == num[j]){
                    fens++;
                }
            }


            if(maxfrequency != fens && minfrequency != fens){
                frequencyNum++;
            }


            // 和最大次数比较，
            // 若大于最大次数，则刷新最大次数元素数为1，
            // 若等于则最大元素次数则最大次数元素数+1
            Set maxSet = new HashSet();
            if (maxfrequency < fens ) {
                maxfrequency = fens;
                maxSet.add(num[i]);
                mapFequency.put("max",maxSet);
            } else if(maxfrequency == fens) {
                // 处理map
                mapFequency.get("max").add(num[i]);
            }

            // 和最小元素比较
            if (minfrequency == 0 || minfrequency > fens ) {
                minfrequency = fens;
                maxSet.add(num[i]);
                mapFequency.put("min",maxSet);
            } else if(minfrequency == fens) {
                // 处理map
                mapFequency.get("min").add(num[i]);
            }
        }
        System.out.println("maxfrequency：" + maxfrequency);
        System.out.println("minfrequency：" + minfrequency);
        System.out.println("frequencyNum：" + frequencyNum);
        System.out.println("mapFequency：" + mapFequency);


        // 跳出递归条件
        // 最大频率和最小频率一致（频率只有一个,且都是相同元素或则都是不同元素）
        if(maxfrequency == minfrequency && frequencyNum == 1
                && (mapFequency.get("max").size() == num.length ||mapFequency.get("max").size() == 1)){
            return num.length;
        }

        // 存在不同的俩个频率 && （ 最小频率为1 || 最大频率比最小频率大1且最大）
        if(frequencyNum == 2 && (
                (minfrequency==1 && mapFequency.get("min").size() ==1)
                 || (maxfrequency - minfrequency)==1 && mapFequency.get("max").size() ==1)
                ){
            return num.length;
        }

        return maxEqualFreq(Arrays.copyOf(num,num.length-1));
    }

}