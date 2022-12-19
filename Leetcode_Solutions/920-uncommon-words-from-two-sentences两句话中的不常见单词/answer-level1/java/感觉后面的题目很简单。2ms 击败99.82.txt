        Map<String,Integer> map = new HashMap<>();
        List<String> list = new ArrayList<>();
        for (String tes : A.split(" "))
            map.put(tes,map.getOrDefault(tes,0)+1);
        for (String value : B.split(" "))
            map.put(value,map.getOrDefault(value,0)+1);
        for (Map.Entry<String,Integer> e : map.entrySet()){
            if (e.getValue() == 1) list.add(e.getKey());
        }
        return list.toArray(new String[]{});