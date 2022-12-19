    public static List<Integer> countSmaller(int[] numbs) {
        int[] input = numbs.clone();
        Arrays.sort(input);
        List<Integer> input2 = Arrays.stream(input).boxed().collect(Collectors.toList());

        List<Integer> output = new ArrayList<>();
        for(Integer current: numbs){
            int pos = input2.indexOf(current);
            output.add(pos);
            input2.remove(pos);
        }
        return output;
    }