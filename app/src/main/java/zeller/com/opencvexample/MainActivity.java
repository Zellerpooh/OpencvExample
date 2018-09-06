package zeller.com.opencvexample;

import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.ImageView;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    private ImageView mIvFace;
    private Bitmap mFaceBitmap;
    private TextView tvResult;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        mIvFace = findViewById(R.id.iv_face);
        tvResult = findViewById(R.id.tv_result);

        mFaceBitmap = BitmapFactory.decodeResource(getResources(), R.drawable.bankcard);
        mIvFace.setImageBitmap(mFaceBitmap);

    }

    public void facedetection(View view) {
        String ocrResult = BankCardOcr.cardOcr(mFaceBitmap);
        tvResult.setText(ocrResult);
    }


}
