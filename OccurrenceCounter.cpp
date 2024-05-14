#include <iostream>
#include <algorithm>
using namespace std;

int findFirstOccurrence(int arr[], int size, int target) {
    int start = 0, end = size - 1, result = -1;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (arr[mid] == target) {
            result = mid;
            end = mid - 1;  
        } else if (arr[mid] < target) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return result;
}

int findLastOccurrence(int arr[], int size, int target) {
    int start = 0, end = size - 1, result = -1;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (arr[mid] == target) {
            result = mid;
            start = mid + 1;  
        } else if (arr[mid] < target) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return result;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter value " << i + 1 << ": ";
        cin >> arr[i];
    }
    sort(arr, arr + n);

    int target;
    cout << "Enter target value: ";
    cin >> target;

    int firstIndex = findFirstOccurrence(arr, n, target);
    if (firstIndex == -1) {
        cout << "Value not found" << endl;
    } else {
        int lastIndex = findLastOccurrence(arr, n, target);
        int count = lastIndex - firstIndex + 1;
        cout << "Value has repeated " << count << " times" << endl;
    }

}


