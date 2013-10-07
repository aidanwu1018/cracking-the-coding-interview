#include <iostream>
using namespace std;

int search(int a[], int low, int high, int x){
    //while(low <= high){
        //cout<<low<<" "<<high<<endl;
        //++cnt;
    int mid = (low+high) / 2;
    if(a[mid] == x) return mid;
    if(high < low) return -1;
    if(a[mid] > a[low]){
        if(x >= a[low] && x <= a[mid]){
            return search(a, low, mid - 1, x);
        } else{
            return search(a, mid + 1, high, x);
        }
    } else if(a[mid] < a[low]){
        if(x >= a[mid] && x <= a[high]){
            return search(a, mid + 1, high, x);
        } else{
            return search(a, low, mid - 1, x);
        }
    } else if(a[low] == a[mid]){
        if(a[mid] != a[high]){
            return search(a, mid + 1, high, x);
        } else{
            int result = search(a, low, mid - 1, x);
            if(result == -1){
                return search(a, mid + 1, high, x);
            } else{
                return result;
            }
        }
    }
    return -1;
}

int main(){
    int a[12] = {
        15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14
    };
    int b[19] = {
        2,2,2,2,2,2,2,2,3,2,2,2,2,2,2,2,2,2,2
    };
    cout<<search(a, 0, 11, 3)<<endl;
    cout<<search(b, 0, 18, 3)<<endl;

    return 0;
}
