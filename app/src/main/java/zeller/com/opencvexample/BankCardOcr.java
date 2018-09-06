package zeller.com.opencvexample;

import android.graphics.Bitmap;

/**
 * Created by Administrator on 2018/9/6.
 */

public class BankCardOcr {

    static {
        System.loadLibrary("native-lib");
    }



    public static native String cardOcr(Bitmap bitmap);

}
