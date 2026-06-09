String[] arr = s.split("");
        Map<String,Integer> m = new HashMap<>();
        for (int i = 0;i < arr.length;i++){
            if (m.containsKey(arr[i])){
                continue;
            }
            int a = s.indexOf(arr[i],i+1);
            if (a == -1){
                return i;
            }
            m.put(arr[i],i);
        }
        return -1;