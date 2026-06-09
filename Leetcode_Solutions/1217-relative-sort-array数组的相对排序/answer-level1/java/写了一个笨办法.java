public int[] relativeSortArray(int[] arr1, int[] arr2) {
        int[] result = new int[arr1.length];
        int k = 0; //result的指针
        for (int i = 0; i < arr2.length; i++) {
            for (int j = 0; j < arr1.length; j++) {
                if (arr1[j] == arr2[i]){
                    result[k++] = arr1[j];
                }
            }
        }
        int[] tmp = new int[arr1.length-k];
        int t = 0;
        List<Integer> list1 = new ArrayList<>();
        for (int i = 0; i < arr1.length; i++) {
            list1.add(arr1[i]);
        }
        List<Integer> list2 = new ArrayList<>();
        for (int i = 0; i < result.length; i++) {
            list2.add(result[i]);
        }
        for (int i = 0; i < list1.size(); i++) {
            if (!list2.contains(list1.get(i))){
                tmp[t++] = list1.get(i);
            }
        }
        Arrays.sort(tmp);
        for (int i = 0; i < tmp.length; i++) {
            result[k++] = tmp[i];
        }
        return result;
    }