其实吧 ，把两个字符串直接拆开来放进hashSet里面，然后这里就要做一个判断了，
就是两个拆分的数组长度必须是相同的，并且两个hashset的hashcode也必须相同。


     public static boolean CheckPermutation(String s1, String s2) {
        String[] split = s1.split("");
        String[] split1 = s2.split("");
        Set hashSet = new HashSet();
        Set hashSet2 = new HashSet();
        for (int i = 0;i <= split.length-1;i++){
            hashSet.add(split[i]);
            hashSet2.add(split1[i]);
        }
        if (split.length == split1.length&&hashSet.hashCode() == hashSet2.hashCode()){
//            System.out.println(hashSet.toString());
//            System.out.println(hashSet2.toString());
            return true;
        }
        System.out.println(hashSet.toString());
        System.out.println(hashSet2.toString());
        return false;
    }