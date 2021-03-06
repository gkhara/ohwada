package jp.ohwada.android.yag1;

import jp.ohwada.android.yag1.task.GeocoderTask;
import android.content.Context;
import android.content.SharedPreferences;
import android.os.Handler;
import android.preference.PreferenceManager;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import com.google.android.maps.GeoPoint;

/**
 * SearchTask
 */
public class SearchTask {

	// object
	private Context mContext;
	private View mView;
	private GeocoderTask mGeocoderTask;

	// view
	private EditText mEditAddress;
	
	/**
	 * === Constructor ===
	 * @param Context context
	 */ 	
	public SearchTask( Context context, View view, Handler handler ) {
    	mGeocoderTask = new GeocoderTask( context, view, handler );
        mContext = context;
    	mView = view;
	}
			
	/**
	 * create
	 */ 	
	public void create() {	    		
		mEditAddress = (EditText) mView.findViewById( R.id.search_edittext_address );
				
		Button btnSearch = (Button) mView.findViewById( R.id.search_button_search );
		btnSearch.setOnClickListener( new View.OnClickListener() {
			@Override
			public void onClick( View view ) {
				searchAddress();
			}
		});
				
	}

	/**
	 * setGeoName
	 */ 	
	public void setGeoName() {
		SharedPreferences pref = PreferenceManager.getDefaultSharedPreferences( mContext );
    	String name = pref.getString( 
    		Constant.PREF_NAME_GEO_NAME, 
    		mContext.getResources().getString( R.string.geo_name ) );
		mEditAddress.setText( name );
	}
	
	/**
	 * getAddressEdit
	 * @return String 
	 */	
	public String getAddressEdit() {
		return mEditAddress.getText().toString();
	}
			
	/**
	 * getPoint
	 * @return GeoPoint
	 */
	public GeoPoint getPoint() {	
		return mGeocoderTask.getResultPoint();
	}

	/**
	 * searchAddress
	 */
	private void searchAddress() {
		String address = getAddressEdit();
		// nothig if no input
		if (( address.length() == 0 )||( address.equals("") )) {
			Toast.makeText ( mContext, R.string.search_please_address, Toast.LENGTH_SHORT ).show();
			return;
		} 
		mGeocoderTask.execute( address );        
	}

	/**
	 * cancel
	 */
	public void cancel() {
		mGeocoderTask.cancel();
	}		
}
