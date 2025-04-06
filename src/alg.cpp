// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len ; ++i) {
    for (int j = i; j < len ; ++j) {
      if (arr[i] + arr[j] == value) {
        count += 1;
        std::cout << arr[i] << std::endl;
      }
    }
  }
return count;
}
int countPairs2(int *arr, int len, int value) {
  int count = 0;
  int lboard = 0;
  int rboard = len;
  for (int i = 0; i < rboard; ++i) {
    for (int j = rboard-1; j>lboard; --j) {
      if (arr[j]>value) {
        rboard -= 1;
      }
      if (arr[i] + arr[j] == value) {
        count += 1;
        std::cout << arr[i] << std::endl;
      }
    }
    lboard += 1;
  }
return count;
}
int countPairs3(int *arr, int len, int value) {
  int count = 0;
  int middle = 0;
  int lboard = 0;
  int rboard = 0;
  int find_num = 0;
  int flag = 0;
  for (int i = 0; i < len-1; ++i) {
    find_num = value - arr[i];
    flag = 0;
    lboard = 0;
    rboard = len - 1;
    while (lboard <= rboard && flag == 0) {
      middle = (lboard + rboard) / 2;
      if (arr[middle] > find_num) {
        rboard = middle - 1;
      }
      else if(arr[middle] < find_num) {
        lboard = middle + 1;
      } else {
        if (arr[middle]!=value) {
          std::cout << arr[i] << std::endl;
          count += 1;
        }
        std::cout << "-" << arr[middle] << std::endl;
        arr[middle] = value;
        flag = 1;
      }
    }
  }
return count;
}
